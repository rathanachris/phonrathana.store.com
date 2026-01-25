import requests

class GitHubClient:
    def __init__(self, api_url, token):
        self.api_url = api_url
        self.headers = {
            "Authorization": f"token {token}",
            "Accept": "application/vnd.github+json"
        }

    def get_repos(self, username):
        url = f"{self.api_url}/users/{username}/repos"
        response = requests.get(url, headers=self.headers)

        if response.status_code != 200:
            raise Exception("GitHub API error")

        return response.json()
