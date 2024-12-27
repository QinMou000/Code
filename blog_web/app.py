from flask import Flask, render_template, request
import markdown
import os
import logging

app = Flask(__name__)

POSTS_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'posts')  # 存储 Markdown 文件的目录

# 定义一个处理 404 错误的视图
@app.errorhandler(404)
def page_not_found(error):
    return render_template('404.html'), 404

@app.route('/')
def index():
    page = request.args.get('page', 1, type=int)
    per_page = 10
    offset = (page - 1) * per_page

    # 获取所有 Markdown 文件
    md_files = [f for f in os.listdir(POSTS_DIR) if f.endswith('.md')] # example.md,wq.md,qw.md
    total_posts = len(md_files)
    md_files = md_files[offset:offset + per_page]

    # 生成文章列表
    posts = [(os.path.splitext(f)[0], f) for f in md_files] # (example,example.md),(wq,wq.md),(qw,qw.md)

    total_pages = (total_posts + per_page - 1) // per_page  # 计算总页数
    return render_template("index.html", posts=posts, page=page, total_pages=total_pages)

@app.route('/posts/<post_id>')
def post_detail(post_id):
    md_file_path = os.path.join(POSTS_DIR, f'{post_id}.md')
    if not os.path.exists(md_file_path):
        logging.error(f"the file {md_file_path} is not found")
        #abort(404)  # 这会自动显示 404 页面

    try:
        with open(md_file_path, 'r', encoding='utf-8') as md_file:
            md_content = md_file.read()
            html_content = markdown.markdown(md_content)
    except UnicodeDecodeError:
        try:
            with open(md_file_path, 'r', encoding='gbk') as md_file:  # 尝试 gbk 编码
                md_content = md_file.read()
                html_content = markdown.markdown(md_content)
        except Exception as e:
            # 记录更详细的错误信息pip install 
            logging.error(f"Error reading file {md_file_path}: {e}")
            #abort(500)  # 内部服务器错误
    return render_template('post_detail.html', post_id=post_id, content=html_content)

if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0", port=8000)
