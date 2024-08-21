import os

import requests
from bs4 import BeautifulSoup
from flask import Flask, render_template_string

#pip install flask
# Flask应用程序
app = Flask(__name__)

# 豆瓣电影Top 50页面的URL
DOUBAN_URL = 'https://movie.douban.com/top250'


# 爬取豆瓣Top 50电影
def scrape_douban_top50():
    headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
    }
    response = requests.get(DOUBAN_URL, headers=headers)
    if response.status_code == 200:
        # 保存HTML文件
        with open('douban_top50.html', 'w', encoding='utf-8') as file:
            file.write(response.text)
        return 'douban_top50.html'
    else:
        raise Exception(f'Failed to retrieve page with status code {response.status_code}')


# 解析HTML文件，提取电影标题和导演
def parse_html(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        soup = BeautifulSoup(file, 'html.parser')
        movies = []

        for item in soup.find_all('div', class_='item'):
            title = item.find('span', class_='title').get_text()
            director = item.find('p').get_text().split('\n')[1].strip()
            movies.append({'title': title, 'director': director})

        return movies


# Flask的路由，展示结果
@app.route('/')
def index():
    # 确保HTML文件存在
    if not os.path.exists('douban_top50.html'):
        scrape_douban_top50()

    movies = parse_html('douban_top50.html')

    # Flask模板
    template = '''
    <!doctype html>
    <html>
    <head>
        <title>Douban Top 50 Movies</title>
    </head>
    <body>
        <h1>Douban Top 50 Movies</h1>
        <ul>
            {% for movie in movies %}
            <li><strong>{{ movie.title }}</strong> - {{ movie.director }}</li>
            {% endfor %}
        </ul>
    </body>
    </html>
    '''
    return render_template_string(template, movies=movies)


if __name__ == '__main__':
    app.run(debug=True)
