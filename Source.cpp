#include <iostream>
#include <vector>

using namespace std;

void print(vector <vector <char>>& ar)
{
	for (int i = 0; i < ar.size(); i++) {
		for (int j = 0; j < ar.size(); j++) {
			cout << ar[i][j] << " ";
		}
		cout << "\n";
	}
}

struct Robot {
	int x = 0;
	int y = 0;
	string dir = "Up";

	void move_forward()
	{
		if (dir == "Up") {
			x--;
		}
		else if (dir == "Right") {
			y++;
		}
		else if (dir == "Down") {
			x++;
		}
		else if (dir == "Left") {
			y--;
		}
	}

	void rotate_right() {
		if (dir == "Up") {
			dir = "Right";
		}
		else if (dir == "Right") {
			dir = "Down";
		}
		else if (dir == "Down") {
			dir = "Left";
		}
		else if (dir == "Left") {
			dir = "Up";
		}
	}

	void rotate_left() {
		if (dir == "Up") {
			dir = "Left";
		}
		else if (dir == "Right") {
			dir = "Up";
		}
		else if (dir == "Down") {
			dir = "Right";
		}
		else if (dir == "Left") {
			dir = "Down";
		}
	}
};

int main()
{
	int n;
	cin >> n;

	if (n < 1) return 0;
	vector <vector <char>> ar(n, vector <char> (n, '.'));

	Robot robot;
	// Robot looks at direction: up

	// paint
	ar[robot.x][robot.y] = '#';
	// + rotate right (current direction: right)
	robot.rotate_right();

	for (int i = 1; i < n; i++) {
		// + rotate right (current direction: down)
		robot.rotate_right();
		// + move forward
		robot.move_forward();
		// + rotate left (current direction: right)
		robot.rotate_left();
		// + move forward
		robot.move_forward();
		// paint
		ar[robot.x][robot.y] = '#';
	}

	// rotate left (current direction: up)
	robot.rotate_left();
	for (int i = n - 1; i > 0; i--) {
		// + move forward
		robot.move_forward();
	}

	// paint
	ar[robot.x][robot.y] = '#';
	// rotate left (current direcion: left)
	robot.rotate_left();
	for (int i = 1; i < n; i++) {
		// + move forward
		robot.move_forward();
		// + rotate left (current direction: down)
		robot.rotate_left();
		// + move forward
		robot.move_forward();
		// paint
		ar[robot.x][robot.y] = '#';
		// + rotate right (current direction: left)
		robot.rotate_right();
	}

	// Diff: 9(N - 1) + 1, ~9N (linear)

	print(ar);
}