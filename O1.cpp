#include <iostream>
#include <vector>

std::vector<std::vector<int>> Graph(20000);
std::vector<std::vector<int>> T_Graph(20000);
std::vector<bool> Check;
std::vector<int> Members;
std::vector<std::vector<int>> Strong_Component(20000);

void DFS_Graph(int v) {
	Check[v] = true;
	for (size_t i = 0; i < Graph[v].size(); ++i)
		if (!Check[Graph[v][i]])
			DFS_Graph(Graph[v][i]);
	Members.push_back(v);
}

void DFS_T_Graph(int v, int size) {
	Check[v] = true;
	Strong_Component[size].push_back(v);
	for (size_t i = 0; i < T_Graph[v].size(); ++i)
		if (!Check[T_Graph[v][i]])
			DFS_T_Graph(T_Graph[v][i], size);
}

int main() {
	int N, M, size = 0;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int first_vertice, second_vertice;
		std::cin >> first_vertice >> second_vertice;
		Graph[first_vertice - 1].push_back(second_vertice - 1);
		T_Graph[second_vertice - 1].push_back(first_vertice - 1);
	}
	Check.assign(N, false);
	for (int i = 0; i < N; ++i)
		if (!Check[i])
			DFS_Graph(i);
	Check.assign(N, false);
	for (int i = 0; i < N; ++i) {
		int vertice = Members[N - 1 - i];
		if (!Check[vertice]) {
			DFS_T_Graph(vertice, size);
			size++;
		}
	}
	std::cout << size << std::endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < Strong_Component[j].size(); k++) {
				if (Strong_Component[j][k] == i)
					std::cout << j + 1 << " ";
			}
		}
	}
}