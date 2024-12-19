import requests
from bs4 import BeautifulSoup
import re

def fetch_tencent_video(url):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    response = requests.get(url, headers=headers)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        video_links = [a['href'] for a in soup.find_all('a', href=True) if 'v.qq.com/x/cover' in a['href']]
        return video_links
    else:
        return None

def download_video(video_url, filename):
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'}
    response = requests.get(video_url, headers=headers, stream=True)
    if response.status_code == 200:
        with open(filename, 'wb') as f:
            for chunk in response.iter_content(chunk_size=1024):
                if chunk:
                    f.write(chunk)
        print(f"Downloaded {filename}")
    else:
        print(f"Failed to download {filename}")

if __name__ == "__main__":
    url = 'https://v.qq.com/'
    video_links = fetch_tencent_video(url)
    if video_links:
        for i, video_link in enumerate(video_links):
            video_page = requests.get(video_link).text
            video_url_match = re.search(r'"url":"(http[^"]+\.mp4)"', video_page)
            if video_url_match:
                video_url = video_url_match.group(1)
                download_video(video_url, f"video_{i}.mp4")
            else:
                print(f"Failed to find video URL for {video_link}")
    else:
        print("Failed to retrieve video links")