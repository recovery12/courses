#!/usr/bin/python3

import pickle
import numpy as np
from flask import Flask, request, jsonify, render_template

app = Flask(__name__)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload():
    if request.method == 'POST':
        f = request.files['upload']
        f.save(f.filename)
        return render_template('index.html', file_name=f.filename)

@app.route('/predict', methods=['POST'])
def predict():
    int_features = np.array([float(x) for x in request.form.values()]).reshape(1, -1)
    predictions = model.predict(int_features)

    output = round(predictions[0], 2)

    return render_template('index.html', prediction_text='Predicted value is: {}'.format(output))

@app.route('/predict_api', methods=['POST'])
def predict_api():
    data = request.get_json(force=True)
    prediction = model.predict([np.array(list(data.values()))])

    output = prediction[0]
    return jsonify(output)

if __name__ == '__main__':
    model = pickle.load(open('model.pkl', 'rb'))
    app.run(debug=True)