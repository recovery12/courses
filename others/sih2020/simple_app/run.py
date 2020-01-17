#!/usr/bin/python3

import os
import re
import pickle
import requests

import numpy as np

from keras.models import Model
from keras.layers.embeddings import Embedding
from keras.layers import BatchNormalization
from keras.regularizers import L1L2
from keras.layers import Dense, Input, Dropout, LSTM, Activation,SpatialDropout1D,Bidirectional

def extract_text():
	file = 'raw.pickle'
	response = requests.get("https://raw.githubusercontent.com/bfelbo/DeepMoji/master/data/PsychExp/raw.pickle")
	open(file, 'wb').write(response.content)
	data = pickle.load(open(file,'rb'),encoding='latin1')
	if os.path.exists('data.txt'):
		os.remove('data.txt')
	try:
		texts = [str(x) for x in data['texts']]
		labels = [x['label'] for x in data['info']]
		with open("data.txt", 'a') as txtfile: 
			for i in range(len(texts)):
				txtfile.write(np.array2string(labels[i]))
				txtfile.write(str(texts[i])+'\n')
	except:
		print('Oops!! An exception has occurred')


def read_text_file(file_name):
	data_list  = []
	with open(file_name,'r') as f:
		for line in f:
			line = line.strip()
			label = ' '.join(line[:line.find("]")].strip().split())
			text = line[line.find("]")+1:].strip()
			data_list.append([label, text])

	return data_list

def extract_labels(text_list):
	label_list = []
	text_list = [text_list[i][0].replace('[','') for i in range(len(text_list))]
	label_list = [list(np.fromstring(text_list[i], dtype=float, sep=' ')) for i in range(len(text_list))]
	return label_list

def extract_text_msgs(text_list):
	msg_list = []
	msg_list = [text_list[i][1] for i in range(len(text_list))]
	return msg_list


def read_glove_vector(glove_file):
	with open(glove_file,'r',encoding='UTF-8') as file:
		words = set()
		word_to_vec = {}
		for line in file:
			line = line.strip().split()
			line[0] = re.sub('[^a-zA-Z]', '', line[0])
			if len(line[0]) > 0:
				words.add(line[0])
				word_to_vec[line[0]] = np.array(line[1:],dtype=np.float64)

		i = 1
		word_to_index = {}
		index_to_word = {}
		for word in sorted(words):
			word_to_index[word] = i
			index_to_word[i] = word
			i = i+1
	return word_to_index,index_to_word,word_to_vec

def create_embedding_layer(word_to_index,word_to_vec):
	corpus_len = len(word_to_index) + 1
	embed_dim = word_to_vec['word'].shape[0]

	embed_matrix = np.zeros((corpus_len,embed_dim))

	for word, index in word_to_index.items():
		embed_matrix[index,:] = word_to_vec[word]

	embedding_layer = Embedding(corpus_len, embed_dim)
	embedding_layer.build((None,))
	embedding_layer.set_weights([embed_matrix])

	return embedding_layer

def create_lstm_model(input_shape,embedding_layer):
	sentence_indices = Input(shape=input_shape, dtype=np.int32)
	embedding_layer =  embedding_layer
	embeddings = embedding_layer(sentence_indices)
	reg = L1L2(0.01, 0.01)

	X = Bidirectional(LSTM(128, return_sequences=True,bias_regularizer=reg,kernel_initializer='he_uniform'))(embeddings)
	X = BatchNormalization()(X)
	X = Dropout(0.5)(X)
	X = LSTM(64)(X)
	X = Dropout(0.5)(X)
	X = Dense(7, activation='softmax')(X)
	X =  Activation('softmax')(X)
	model = Model(sentence_indices, X)

	return model

if __name__ == '__main__':
    # Maximum length of the input text sequences.
    maxlen = 50 
    model = create_lstm_model((maxlen,), embedding_layer)