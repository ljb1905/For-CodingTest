import requests
import json

#start API
url = 'url'
headers = {'X-Auth-Token': 'val', 'Content-Type': 'application/json'}
parameter = {'problem': 1}
r = requests.post(url+'/start', headers=headers, params=parameter)
print(r.json())

#location API
headers = {'Authorization' : 'val', 'Content-Type': 'application/json'}
r = requests.get(url+'/locations', headers=headers)

print(r.json())

#simulate API
parameter = {}
parameter['commands'] = []
parameter['commands'].append({
    "truck_id": 0,
    "command": [2, 5, 4, 1, 6]
})

r = requests.put(url+'/simulate', headers=headers, data=json.dumps(parameter))
print(r.json())