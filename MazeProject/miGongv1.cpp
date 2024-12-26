#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <ctime>
#include <limits>

using namespace std;

const int MAX_SIZE = 100; // Максимальный размер лабиринта

// 结构体表示迷宫中的一个点
struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
};

// 检查移动是否有效
bool isValidMove(int maze[MAX_SIZE][MAX_SIZE], 
                 bool visited[MAX_SIZE][MAX_SIZE], 
                 int x, int y, int rows, int cols)
{
    return (x >= 0 && x < rows && y >= 0 && y < cols && 
            maze[x][y] == 0 && !visited[x][y]);
}

// 使用广度优先搜索（BFS）寻找从起点到终点的路径
bool findSolution(int maze[MAX_SIZE][MAX_SIZE], Point start, Point end, 
                  Point path[MAX_SIZE * MAX_SIZE], int& pathLength, int rows, int cols)
{
    bool visited[MAX_SIZE][MAX_SIZE] = {false};
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;
    Point directions[4] = {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)};
    Point parent[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            parent[i][j] = Point(-1, -1);
        }
    }

    while (!q.empty())
    {
        Point current = q.front();
        q.pop();

        // 如果到达终点，使用栈恢复路径
        if (current.x == end.x && current.y == end.y)
        {
            stack<Point> s;
            Point p = end;
            while (!(p.x == start.x && p.y == start.y))
            {
                s.push(p);
                p = parent[p.x][p.y];
            }
            s.push(start);
            pathLength = 0;
            while (!s.empty())
            {
                path[pathLength++] = s.top();
                s.pop();
            }
            return true;
        }

        // 检查所有可能的移动方向
        for (auto& dir : directions)
        {
            int newX = current.x + dir.x;
            int newY = current.y + dir.y;
            if (isValidMove(maze, visited, newX, newY, rows, cols))
            {
                q.push(Point(newX, newY));
                visited[newX][newY] = true;
                parent[newX][newY] = current;
            }
        }
    }
    return false;
}

// 打印迷宫和找到的路径
void printMaze(int maze[MAX_SIZE][MAX_SIZE], Point path[MAX_SIZE * MAX_SIZE], int pathLength, int rows, int cols)
{
    for (int i = 0; i < pathLength; ++i)
    {
        maze[path[i].x][path[i].y] = 2; // 用 '2' 表示路径
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (maze[i][j] == 1)
            {
                cout << "▇"; // 墙壁
            }
            else if (maze[i][j] == 2)
            {
                cout << "※"; // 路径
            }
            else
            {
                cout << "□"; // 通路
            }
        }
        cout << endl;
    }
}

// 将迷宫保存到文件
void saveMaze(const string& filename, int maze[MAX_SIZE][MAX_SIZE], 
              Point start, Point end, bool savePath, int rows, int cols)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << rows << " " << cols << " " << start.x << " " << 
                   start.y << " " << end.x << " " << end.y << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (maze[i][j] == 2 && !savePath)
                {
                    outFile << 0; // 清零路径，如果不需要保存路径
                }
                else
                {
                    outFile << maze[i][j];
                }
            }
            outFile << endl;
        }
        outFile.close();
    }
}

// 从文件加载迷宫
bool loadMaze(const string& filename, int maze[MAX_SIZE][MAX_SIZE], Point& start, Point& end, int& rows, int& cols)
{
    ifstream inFile(filename);
    if (inFile.is_open())
    {
        inFile >> rows >> cols >> start.x >> start.y >> end.x >> end.y;
        if (cin.fail() || rows < 3 || cols < 3 || rows > MAX_SIZE || cols > MAX_SIZE || 
            start.x < 1 || start.y < 1 || start.x > rows - 2 || start.y > cols - 2 ||
            end.x < 1 || end.y < 1 || end.x > rows - 2 || end.y > cols - 2)
        {
            cout << "文件里无效的迷宫大小。" << endl;
            return false;
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                char cell;
                inFile >> cell;
                if (cell != '0' && cell != '1' && cell != '2')
                {
                    cout << "迷宫里的数据无效。" << endl;
                    return false;
                }
                maze[i][j] = cell - '0'; // 将字符转换为整数
                if (maze[i][j] == 2) maze[i][j] = 0;    
            }
        }
        inFile.close();
        return true;
    }
    return false;
}

// 生成随机迷宫并确保至少有一条路径
void generateMaze(int maze[MAX_SIZE][MAX_SIZE], int rows, int cols, Point& start, Point& end)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            maze[i][j] = 1; // 初始化迷宫，全部为墙壁
        }
    }
    srand(time(0)); // 初始化随机数生成器

    // 使用 Prim 算法生成迷宫
    Point walls[MAX_SIZE * MAX_SIZE];
    int wallCount = 0;
    start = Point(1, 1);
    end = Point(rows - 2, cols - 2);
    maze[start.x][start.y] = 0;

    // 添加初始墙壁 (在（1 1）点旁边)
    if (start.x + 2 < rows) walls[wallCount++] = Point(start.x + 2, start.y);
    if (start.y + 2 < cols) walls[wallCount++] = Point(start.x, start.y + 2);

    while (wallCount > 0)
    {
        int randomIndex = rand() % wallCount;
        Point wall = walls[randomIndex];
        walls[randomIndex] = walls[--wallCount];

        Point neighbors[4];
        int neighborPointCount = 0;
        if (wall.x >= 2 && maze[wall.x - 2][wall.y] == 0) neighbors[neighborPointCount++] = Point(wall.x - 2, wall.y);
        if (wall.y >= 2 && maze[wall.x][wall.y - 2] == 0) neighbors[neighborPointCount++] = Point(wall.x, wall.y - 2);
        if (wall.x + 2 < rows && maze[wall.x + 2][wall.y] == 0) neighbors[neighborPointCount++] = Point(wall.x + 2, wall.y);
        if (wall.y + 2 < cols && maze[wall.x][wall.y + 2] == 0) neighbors[neighborPointCount++] = Point(wall.x, wall.y + 2);

        if (neighborPointCount == 1)
        {
            Point neighbor = neighbors[0];
            maze[wall.x][wall.y] = 0;
            maze[(wall.x + neighbor.x) / 2][(wall.y + neighbor.y) / 2] = 0;

            if (wall.x >= 2 && maze[wall.x - 2][wall.y] == 1) walls[wallCount++] = Point(wall.x - 2, wall.y);
            if (wall.y >= 2 && maze[wall.x][wall.y - 2] == 1) walls[wallCount++] = Point(wall.x, wall.y - 2);
            if (wall.x + 2 < rows && maze[wall.x + 2][wall.y] == 1) walls[wallCount++] = Point(wall.x + 2, wall.y);
            if (wall.y + 2 < cols && maze[wall.x][wall.y + 2] == 1) walls[wallCount++] = Point(wall.x, wall.y + 2);
        }
    }

    // 确保出口是通的
    maze[end.x][end.y] = 0;

    // 设置所有边界墙
    for (int i = 0; i < rows; ++i)
    {
        maze[i][0] = 1; // 设置上边界
        maze[i][cols - 1] = 1; // 设置下边界
    }
    for (int j = 0; j < cols; ++j)
    {
        maze[0][j] = 1; // 设置左边界
        maze[rows - 1][j] = 1; // 设置右边界
    }

    // 确保出口周围有通路
    Point directions[4] = {Point(0, 1), Point(1, 0), Point(0, -1), Point(-1, 0)};
    for (auto& dir : directions)
    {
        int newX = end.x + dir.x;
        int newY = end.y + dir.y;
        if (newX > 0 && newX < rows - 1 && newY > 0 && newY < cols - 1)
        {
            maze[newX][newY] = 0;
        }
    }

    // 检查是否有没有障碍的通路
    for (auto& dir : directions)
    {
        int newX = end.x + dir.x * 2;
        int newY = end.y + dir.y * 2;
        if (newX > 0 && newX < rows - 1 && newY > 0 && newY < cols - 1)
        {
            maze[newX][newY] = 0;
        }
    }
}

int main()
{
    int maze[MAX_SIZE][MAX_SIZE];
    Point start(0, 0), end(0, 0);
    string filename = "maze.txt";
    int rows = 0, cols = 0;

    cout << "1. 从文件加载迷宫\n2. 生成新迷宫\n选择一个选项: ";
    int choice;
    while (true)
    {
        cin >> choice;
        if (cin.fail() || (choice != 1 && choice != 2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "无效选项，请重新选择: ";
        }
        else
        {
            break;
        }
    }

    if (choice == 1)
    {
        if (loadMaze(filename, maze, start, end, rows, cols) == false) return -1;
    }
    else if (choice == 2)
    {
        while (rows < 3 || cols < 3 || rows > MAX_SIZE || cols > MAX_SIZE)
        {
            cout << "输入迷宫的行数和列数 (rows cols): ";
            cin >> rows >> cols;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "无效输入，";
                rows = 0;
                cols = 0;
            }
        }
        
        generateMaze(maze, rows, cols, start, end);
    }

    // 打印生成的迷宫
    Point emptyPath[MAX_SIZE * MAX_SIZE];
    int emptyPathLength = 0;

    // 读文件后直接处理迷宫问题按照得到的坐标值
    if (choice == 1)
    {
        Point path[MAX_SIZE * MAX_SIZE];
        int pathLength;
        if (findSolution(maze, start, end, path, pathLength, rows, cols))
        {
            printMaze(maze, path, pathLength, rows, cols);
            char save = 'a';
            bool savePath = false;
            while (save != 'y' && save != 'Y' && save != 'n' && save != 'N')
            {
                cout << "是否保存迷宫到maze.txt文件 (y/n): ";
                cin >> save;
                if (save == 'n' || save == 'N')
                {
                    return 0;
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
                
            char savePathChoice = 'a';
            while (savePathChoice != 'y' && savePathChoice != 'Y' &&
                savePathChoice != 'n' && savePathChoice != 'N')
            {
                cout << "是否保存路径 (y/n): ";
                cin >> savePathChoice;
            }
            if (savePathChoice == 'y' || savePathChoice == 'Y')
            {
                savePath = true;
            }
            else
            {
                savePath = false;
            }

            saveMaze(filename, maze, start, end, savePath, rows, cols);
            cout << "保存成功！" << endl;
        }
        else
        {
            cout << "在这个文件没有找到路径。" << endl;
        }
        return 0;
    }


    // 打印生成的迷宫和请求用户输入起点和终点
    printMaze(maze, emptyPath, emptyPathLength, rows, cols);
    cout << "输入起点 (x y): ";
    cin >> start.x >> start.y;
    while (cin.fail() || start.x < 1 || start.y < 1 ||
                         start.x > rows - 2 || start.y > cols - 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效输入，请重新输入起点 (x y): ";
        cin >> start.x >> start.y;
    }
    cout << "输入终点 (x y): ";
    cin >> end.x >> end.y;
    while (cin.fail() || end.x < 1 || end.y < 1 ||
                         end.x > rows - 2 || end.y > cols - 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "无效输入，请重新输入终点 (x y): ";
        cin >> end.x >> end.y;
    }

    Point path[MAX_SIZE * MAX_SIZE];
    int pathLength;
    if (findSolution(maze, start, end, path, pathLength, rows, cols))
    {
        printMaze(maze, path, pathLength, rows, cols);
    }
    else
    {
        cout << "没有找到路径。" << endl;
    }
    
    char save = 'a';
    bool savePath = false;
    while (save != 'y' && save != 'Y' && save != 'n' && save != 'N')
    {
        cout << "是否保存迷宫到maze.txt文件 (y/n): ";
        cin >> save;
        if (save == 'n' || save == 'N')
        {
            return 0;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
        
    char savePathChoice = 'a';
    while (savePathChoice != 'y' && savePathChoice != 'Y' &&
           savePathChoice != 'n' && savePathChoice != 'N')
    {
        cout << "是否保存路径 (y/n): ";
        cin >> savePathChoice;
    }
    if (savePathChoice == 'y' || savePathChoice == 'Y')
    {
        savePath = true;
    }
    else
    {
        savePath = false;
    }

    saveMaze(filename, maze, start, end, savePath, rows, cols);
    cout << "保存成功！" << endl;

    return 0;
}