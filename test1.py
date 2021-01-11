import re
import pandas as pd
filepath  = '4F-group.txt'
f = open(filepath)
char1 =[]
char2 =[]
zidian = {}
for line2 in f:
    if "IFCRELASSIGNSTOGROUP" in line2:
      seg = re.findall(r'[(][#](.*?)[)]', line2)[0]
      seg1 = re.findall(r'[$][,](.*?)[)][;]', line2)[0]
      seg1 = seg1.split(',')
      seg1 = seg1[-1]
      seg = "#" + seg
      seg =seg.split(",")
      char1.extend(seg) 
      for i in range(len(seg)):
        zidian[seg[i]] = seg1
      char2.append(seg1)
    else:
      continue
shuju = []
shuju1 =[]
shuju2= []
zidian1 = {}
f = open(filepath)
for line2 in f:
    try:
        re.findall(r'[#](.*?)[=]', line2)[0]
    except:
      continue
    else:
      seg = re.findall(r'[#](.*?)[=]', line2)[0]
      seg = "#" + seg
      if seg in char2:
        want= re.findall(r'[:](.*?)[:]', line2)[0]
        zidian1[seg] = want
f = open(filepath)
for line2 in f:
    try:
        re.findall(r'[#](.*?)[=]', line2)[0]
    except:
      continue
    else:
      seg = re.findall(r'[#](.*?)[=]', line2)[0]
      seg = "#" + seg
      if seg in char1:
        if "Precast" in line2 :
          want= re.findall(r'[(](.*?)[)]', line2)[0]
          want =  re.findall(r'[:](.*?)[\']', want)[0]
          want = want.split(":")
          want = want[0]  
          shuju.append(want)
          shuju1.append(zidian1[zidian[seg]])
          an = zidian1[zidian[seg]]
          ind = an.find("Flat")
          shuju2.append(int (an[ind+4:] ))
        else:
         want= re.findall(r'[:](.*?)[:]', line2)[0]
         shuju.append(want) 
         shuju1.append(zidian1[zidian[seg]])
         an = zidian1[zidian[seg]]
         ind = an.find("Flat")
         shuju2.append(int (an[ind+4:] ))
      else:
        continue
df = pd.DataFrame({"1": shuju, "2":shuju1, "3":shuju2},columns = ['1','2','3'])
df.sort_values(by='3',inplace=True)
df = pd.DataFrame({"1":df['1'], "2":df["2"]})
df.to_excel("testxjy-one flat.xlsx" )
    