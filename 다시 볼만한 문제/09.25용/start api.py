import requests

url = 'url/start'
headers = {'X-Auth-Token': 'val', 'Content-Type': 'application/json'}
parameter = {'problem': 1}
r = requests.post(url, headers=headers, params=parameter)