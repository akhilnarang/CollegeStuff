from flask import Flask, request, url_for, redirect
from gpiozero import LED
import time

app = Flask(__name__)
led = LED(2)


@app.route('/', methods=["GET", "POST"])
def main():
    if request.method == 'GET':
        return """
<form action='' method='post'>
<input type="text" id="stuff" name="stuff" style="visibility: hidden" value="On" contenteditable="false">
<input type=submit value='On'>
</form>
<form action='' method='post'>
<input type="text" id="stuff" name="stuff" style="visibility: hidden" value="Off" contenteditable="false">
<input type=submit value='Off'>
</form>
"""
    if request.form["stuff"] == 'On':
        led.on()
    elif request.form["stuff"] == 'Off':
        led.off()
    else:
        pass
    return redirect(url_for('main'))


if __name__ == '__main__':
    app.run()
