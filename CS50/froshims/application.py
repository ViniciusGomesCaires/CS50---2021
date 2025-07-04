import os

from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message

app = Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = os.getnev("MAIL_DEFAUKT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

SPORTS = [
        "Dodgeball",
        "Flag Football",
        "Soccer",
        "Volleyball",
        "Ultimate Frisbee"
]

@app.route("/")
def index():
        return render_template ("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
        email = request.form.get("email")
        if not email:
            return render_template("error.html", "Missing email")
        sport = request.form.get("sport")
        if not sport:
             return render_template("error.html", "Missing sport")
        if sport not in SPORTS:
              return render_template("error.html", "Invalid sport")

        message = Message("You are registered!", recipients=[email])
        mail. send(message)

        return render_template("success.html")