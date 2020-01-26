#!/usr/bin/python3

# Importing Libraries
import pickle
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Loading the dataset
dataset = pd.read_csv('CarPrice_Assignment.csv')

# Data Pre-processing
dataset = dataset.dropna()

# Creating a model
reg = LinearRegression()
reg.fit(dataset.iloc[:, :2], dataset['y'])     # fitting

# Saving the model
pickle.dump(reg, open('model.pkl', 'wb'))