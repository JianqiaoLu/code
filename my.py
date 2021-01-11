from playwright import sync_playwright

def run(playwright):
    browser = playwright.chromium.launch(headless=False)
    context = browser.newContext()

    # Open new page
    page = context.newPage()

    # Go to https://www.zhihu.com/signin?next=%2F
    page.goto("https://www.zhihu.com/signin?next=%2F")

    # Close page
    page.close()

    # ---------------------
    context.close()
    browser.close()

with sync_playwright() as playwright:
    run(playwright)