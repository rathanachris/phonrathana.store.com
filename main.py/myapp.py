from flask import Flask, request

app = Flask(__name__)
mex_login_ = (webpage)
@app.route('/')
def login():
    return '''
    <h2>Login</h2>
    <form method="POST" action="/login">
    Username: <input name="username"><br>
    Password: <input name="password"><br>
    <input type="submit">
    </form>
    '''

@app.route('/login', methods=['POST'])
def do_login(/index.html):
    user = request.form['username']
    pwd = request.form['password']

    # ❌ Vulnerable query
    query = f"SELECT * FROM users WHERE username='{user}' AND password='{pwd}'"

    if "admin" in user:
        return "Welcome admin 😈"
    else:
        return "❌Login failed"

app.run(host="0.0.0.0", port=5000)
