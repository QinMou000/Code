import requests
from bs4 import BeautifulSoup
import os

# CSDN 用户名
USER = "2301_80194476"
BLOG_URL = f"https://blog.csdn.net/{USER}"

# 创建目录保存博客
if not os.path.exists("blogs"):
    os.mkdir("blogs")

def get_blog_links():
    """获取博客文章链接"""
    response = requests.get(BLOG_URL)
    soup = BeautifulSoup(response.text, 'html.parser')
    
    # 找到文章链接（调整 CSS 类以适配 CSDN 页面结构）
    articles = soup.find_all('a', class_='blog-title-link')  # CSS 类可能需要修改
    links = [a['href'] for a in articles]
    return links

def save_blog(link):
    """抓取并保存单篇博客"""
    response = requests.get(link)
    soup = BeautifulSoup(response.text, 'html.parser')

    # 提取标题和内容
    title = soup.find('h1').text.strip()  # 根据实际结构调整
    content = soup.find('div', class_='article-content').prettify()

    # 保存为 Markdown 文件
    filename = f"blogs/{title.replace('/', '-')}.md"
    with open(filename, "w", encoding="utf-8") as f:
        f.write(f"# {title}\n\n")
        f.write(content)

    print(f"Saved: {filename}")

def main():
    links = get_blog_links()
    for link in links:
        save_blog(link)

if __name__ == "__main__":
    main()
