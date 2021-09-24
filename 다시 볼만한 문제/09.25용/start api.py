import requests

url = 'url'
headers = {'X-Auth-Token': 'val', 'Content-Type': 'application/json'}
parameter = {'problem': 1}
r = requests.post(url+'/start', headers=headers, params=parameter)