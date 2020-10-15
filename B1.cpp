#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> Graph(N);
	std::vector<char> Part(N, -1);
	std::vector<int> Queue(N);
	bool ok = true;
	for (int i = 0; i < M; i++) {
		int first_student, second_student;
		std::cin >> first_student >> second_student;
		Graph[first_student - 1].push_back(second_student - 1);
		Graph[second_student - 1].push_back(first_student - 1);
	}
	for (int i = 0; i < N; ++i)
		if (Part[i] == -1) {
			int first = 0, second = 0;
			Queue[second++] = i;
			Part[i] = 0;
			while (first < second) {
				int student = Queue[first++];
				for (int j = 0; j < Graph[student].size(); ++j) {
					int student_neighbour = Graph[student][j];
					if (Part[student_neighbour] == -1) {
						Part[student_neighbour] = !Part[student];
						Queue[second++] = student_neighbour;
					}
					else
						ok &= Part[student_neighbour] != Part[student];
				}
			}
		}
	if (ok) std::cout << "YES";
	else std::cout << "NO";
	return 0;
}