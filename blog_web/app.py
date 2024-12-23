from flask import Flask, render_template, request
import sqlite3
#import markdown
#import os
#import json

app = Flask(__name__)

# # 存储 Markdown 文件的目录
# ARTICLES_PATH = "blogs"

# def list_articles():
#     """列出所有文章标题和路径"""
#     articles = []
#     for file_name in os.listdir(ARTICLES_PATH):
#         if file_name.endswith('.md'):
#             article_path = os.path.join(ARTICLES_PATH, file_name)
#             articles.append({
#                 "title": os.path.splitext(file_name)[0],  # 文件名作为标题
#                 "file": file_name
#             })
#     return jsonify(articles)

# @app.route('/api/articles/<file_name>', methods=['GET'])
# def get_article(file_name):
#     """返回单篇文章的 HTML 内容"""
#     file_path = os.path.join(ARTICLES_PATH, file_name)
#     if os.path.exists(file_path) and file_name.endswith('.md'):
#         with open(file_path, 'r', encoding='utf-8') as f:
#             md_content = f.read()
#         # 转换 Markdown 为 HTML
#         html_content = markdown.markdown(md_content)
#         return jsonify({"content": html_content})
#     return jsonify({"error": "File not found"}), 404

# 初始化数据库
def init_db():
    try:
        with sqlite3.connect("blog.db") as conn:
            conn.execute('''
                CREATE TABLE IF NOT EXISTS posts (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    title TEXT NOT NULL,
                    content TEXT NOT NULL
                )
            ''')
            conn.commit()
    except sqlite3.Error as e:
        print(f"Database error: {e}")

# 插入测试数据
def insert_test_data():
    try:
        with sqlite3.connect("blog.db") as conn:
            conn.execute('INSERT INTO posts (title, content) VALUES (?, ?)', 
                         ("C进阶哈希", "异常的概念异常处理机制允许程序中独⽴开发的部分能够在运⾏时就出\
                          现的问题进⾏通信并做出相应的处理， 异常使得我们能够将问题的检测与解决问题的过程分开，\
                          程序的⼀部分负责检测问题的出现，然后解决问题的任务传递给程序的另⼀部分，检测环节⽆须知\
                          道问题的处理模块的所有细节。C语⾔主要通过错误码的形式处理错误，错误码本质就是对错误信\
                          息进⾏分类编号，拿到错误码以后还要去查询错误信息，⽐较⿇烦。异常时抛出⼀个对象，这个对\
                          象可以涵盖更全⾯的各种信息。"))
            conn.commit()
    except sqlite3.Error as e:
        print(f"Database error: {e}")

# 在应用启动时调用初始化函数
with app.app_context():
    init_db()
    insert_test_data()

@app.route("/")
def index():
    # 从数据库中获取所有博客文章
    with sqlite3.connect("blog.db") as conn:
        cur = conn.cursor()
        cur.execute("SELECT * FROM posts")
        posts = cur.fetchall()
    return render_template("index.html", posts=posts)

@app.route("/search", methods=["GET"])
def search():
    query = request.args.get("query", "")
    with sqlite3.connect("blog.db") as conn:
        cur = conn.cursor()
        cur.execute("SELECT * FROM posts WHERE title LIKE ? OR content LIKE ?", 
                    (f"%{query}%", f"%{query}%"))
        results = cur.fetchall()
    return render_template("search.html", query=query, results=results)

if __name__ == "__main__":
    app.run(debug=True, host="127.0.0.1", port=8000)
