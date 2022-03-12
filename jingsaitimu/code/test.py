class Seq2Seq(nn.Module):
      def __init__(self, encoder, decoder, device):
    super().__init__()
    self.encoder = encoder
    self.decoder = decoder
    self.device = device
    assert encoder.n_layers == decoder.n_layers, \
            "Encoder and decoder must have equal number of layers!"
            
  def forward(self, input, target, teacher_forcing_ratio):
    # input  = [batch size, input len, vocab size]
    # target = [batch size, target len, vocab size]
    # teacher_forcing_ratio 是有多少機率使用正確答案來訓練
    batch_size = target.shape[0]
    target_len = target.shape[1]
    vocab_size = self.decoder.cn_vocab_size

    # 準備一個儲存空間來儲存輸出
    outputs = torch.zeros(batch_size, target_len, vocab_size).to(self.device)
    # 將輸入放入 Encoder
    encoder_outputs, hidden = self.encoder(input)
    # Encoder 最後的隱藏層(hidden state) 用來初始化 Decoder
    # Encoder_outputs 主要是使用在 Attention
    # 因為 Encoder 是雙向的RNN，所以需要將同一層兩個方向的 hidden state 接在一起
    # hidden =  [num_layers * directions, batch size  , hid dim]  --> [num_layers, directions, batch size  , hid dim]
    hidden = hidden.view(self.encoder.n_layers, 2, batch_size, -1)
    hidden = torch.cat((hidden[:, -2, :, :], hidden[:, -1, :, :]), dim=2)
    # 取的 <BOS> token
    input = target[:, 0]
    preds = []
    for t in range(1, target_len):
      output, hidden = self.decoder(input, hidden, encoder_outputs)
      outputs[:, t] = output
      # 決定是否用正確答案來做訓練
      teacher_force = random.random() <= teacher_forcing_ratio
      # 取出機率最大的單詞
      top1 = output.argmax(1)
      # 如果是 teacher force 則用正解訓練，反之用自己預測的單詞做預測
      input = target[:, t] if teacher_force and t < target_len else top1
      preds.append(top1.unsqueeze(1))
    preds = torch.cat(preds, 1)
    return outputs, preds

  def inference(self, input, target):
    ########
    # TODO #
    ########
    # 在這裡實施 Beam Search
    # 此函式的 batch size = 1  
    # input  = [batch size, input len, vocab size]
    # target = [batch size, target len, vocab size]
    batch_size = input.shape[0]
    input_len = input.shape[1]        # 取得最大字數
    vocab_size = self.decoder.cn_vocab_size

    # 準備一個儲存空間來儲存輸出
    outputs = torch.zeros(batch_size, input_len, vocab_size).to(self.device)
    # 將輸入放入 Encoder
    encoder_outputs, hidden = self.encoder(input)
    # Encoder 最後的隱藏層(hidden state) 用來初始化 Decoder
    # encoder_outputs 主要是使用在 Attention
    # 因為 Encoder 是雙向的RNN，所以需要將同一層兩個方向的 hidden state 接在一起
    # hidden =  [num_layers * directions, batch size  , hid dim]  --> [num_layers, directions, batch size  , hid dim]
    hidden = hidden.view(self.encoder.n_layers, 2, batch_size, -1)
    hidden = torch.cat((hidden[:, -2, :, :], hidden[:, -1, :, :]), dim=2)
    # 取的 <BOS> token
    input = target[:, 0]
    preds = []
    indexlists = [[input],[input],[input],[input]]
    outputlists = torch.zeros(4,batch_size, input_len, vocab_size).to(self.device)
    marklists = [1,1,1,1]
    intputlists = [input,input]
    for t in range(1, input_len):
      for i in range(0,2):
        input = inputlists[i]
        output, hidden = self.decoder(input, hidden, encoder_outputs)
      # 將預測結果存起來
        outputlists[i, : ,t, ] = output
        top1 = output.argmax(1)
        top2 = top1;
        indexlists[2 * i ].append(top1.unsqueeze(1))
        indexlists[2 * i + 1].append(top2.unsqueeze(1))
        marklist[2 * i] = marklist[2 * i] * output[top1]
        marklist[2 * i + 1] = marklist[2 * i + 1] * output[top1]
      top1 = marklist.argmax(1)
      top2 = marklist.argmax(1)
      if(t == input_len - 1):
            preds = indexlists[0]
            outputs = outputlists[0]
            preds = indexlists[top1]
            preds = torch.cat(preds, 1)
            return outputs, preds
      inputlist[0] = indexlists[top1][-1]
      inputlist[1] = indexlists[top2][-1]
      marklist = [marklist[top1],marklist[top1] ,marklist[top2] ,marklist[top2] ]
      indexlists = [indexlists[top1],indexlists[top1],indexlists[top2],indexlists[top2]]
      outputlists[0] = outputlists[top1/2]
      outputlists[1] = outputlists[top2/2]
      # 取出機率最大的單詞
      top1 = output.argmax(1)
      input = top1
      preds.append(top1.unsqueeze(1))