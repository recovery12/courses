
import json

n = int(input())

details = json.loads(input())
l = len(details['articleCounts'])

params = [[0 for i in range(3)] for i in range(l)]

for i in range(l):
    params[i][0] = details['publications'][i]['publicationTitle']

for i in range(1, n):
    arr.append(json.loads(input()))
    num = int(arr[i-1]['title'][-1])
    for cite in arr[i-1]['paperCitations']['ieee']:
        if cite['year'] in [2018, 2017]:
            params[num-1][2]