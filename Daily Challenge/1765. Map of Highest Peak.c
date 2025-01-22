/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct
{
    int x;
    int y;
} Node;

int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int isValid(int x, int y, int row, int column)
{
    return x >= 0 && y >= 0 && y < column && x < row;
}
int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes) 
{
    *returnSize = isWaterSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * isWaterSize);
    int** height = (int**)malloc(sizeof(int*) * isWaterSize);
    for(int i = 0; i < isWaterSize; i++)
    {
        (*returnColumnSizes)[i] = *isWaterColSize;
        height[i] = (int*)malloc(sizeof(int) * *isWaterColSize);
        for(int j = 0; j < *isWaterColSize; j++)
        {
            height[i][j] = -1;
        }
    }

    
    Node* queue = (Node*)malloc(sizeof(Node) * isWaterSize * *isWaterColSize);
    int front = 0;
    int rear = 0;
    for(int i = 0; i < isWaterSize; i++)
    {
        for(int j = 0; j < *isWaterColSize; j++)
        {
            if(isWater[i][j] == 1)
            {
                height[i][j] = 0;
                queue[rear++] = (Node){i, j};
            }
        }
    }

    while(front < rear)
    {
        Node current = queue[front++];
        int x = current.x;
        int y = current.y;
        for(int d = 0; d < 4; d++)
        {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];
            if(isValid(nx, ny, isWaterSize, *isWaterColSize) && height[nx][ny] == -1)
            {
                height[nx][ny] = height[x][y] + 1;
                queue[rear++] = (Node){nx, ny};
            }
        }
    }
    free(queue);
    return height;
}
