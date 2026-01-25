import json
from github_client import GitHubClient

def load_config():
    with open("../config/github.json", "r") as f:
        return json.load(f)

def main():
    config = load_config()

    github = GitHubClient(
        api_url=config["api_url"],
        token=config["token"]
    )

    repos = github.get_repos(config["username"])

    print("📦 GitHub Repositories:")
    for repo in repos:
        print("-", repo["name"])

if __name__ == "__main__":
    main()
