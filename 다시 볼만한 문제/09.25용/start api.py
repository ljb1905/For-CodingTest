import requests

url = 'https://kox947ka1a.execute-api.ap-northeast-2.amazonaws.com/prod/users/start'
headers = {'X-Auth-Token': 'f366db55a4dd0893c9bd15a5ce46c858', 'Content-Type': 'application/json'}
parameter = {'problem': 1}
r = requests.post(url, headers=headers, params=parameter)