#include <iostream>
#include <vector>
#include <queue>

int main() {
	int n, m, a, b;
	std::cin >> n >> m >> a >> b;
	std::vector<std::vector<int>> Graph(n);
	std::queue<int> Queue;
	std::vector<bool> Check(n);
	std::vector<int> Way;
	std::vector<int> Distance(n);
	std::vector<int> Parents(n);
	for (int i = 0; i < m; i++) {
		int first_vertice, second_vertice;
		std::cin >> first_vertice >> second_vertice;
		Graph[first_vertice - 1].push_back(second_vertice - 1);
		Graph[second_vertice - 1].push_back(first_vertice - 1);
	}
	for (int i = 0; i < n; i++) {
		Check[i] = false;
	}
	Check[a - 1] = true;
	Queue.push(a - 1);
	Parents[a - 1] = -1;
	while (!Queue.empty()) {
		int vertice = Queue.front();
		Queue.pop();
		for (int i = 0; i < Graph[vertice].size(); ++i) {
			int neighbour = Graph[vertice][i];
			if (!Check[neighbour]) {
				Check[neighbour] = true;
				Queue.push(neighbour);
				Distance[neighbour] = Distance[vertice] + 1;
				Parents[neighbour] = vertice;
			}
		}
	}
	if (Check[b - 1]) {
		for (int i = b - 1; i != -1; i = Parents[i]) {
			Way.push_back(i);
		}
		reverse(Way.begin(), Way.end());
		std::cout << Distance[b - 1] << std::endl;
		for (int i = 0; i < Way.size(); ++i) {
			std::cout << Way[i] + 1 << " ";
		}
	}
	else std::cout << -1;
	return 0;
}