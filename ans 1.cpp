#include <stdio.h>
int main()
{
    int n, m, i, j, k, alloc[10][10], max[10][10],avail[10],u,r;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    printf("Enter number of resources:\n");
    scanf("%d",&m);
    printf("Enter the allocation values for each resource in the %d processes:\n", n);
    for(u=0; u<n; u++)
    {
        for(r=0; r<m; r++)
        {
            scanf("%d",&alloc[u][r]);
        }
    }
    printf("Enter the maximum values for each resource in the %d processes:\n", n);
    for(int u=0; u<n; u++)
    {
        for(int r=0; r<m; r++)
        {
            scanf("%d",&max[u][r]);
        }
    }
    printf("Enter the available values for each resource:\n", n);
    for(int r=0; r<m; r++)
    {
        scanf("%d",&avail[r]);
    }
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++)
    {
        f[k] = 0;  //initializes the finish array of every process to zero.
    }
    printf("The Need matrix:\n");
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j]; //forms the need matrix by deducting allocation from maximum
    }
    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0) //checks if the process is already finished or not
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1; //skips the processes where need > available
                        break;
                    }
                }
                if (flag == 0) //for processes where need <= avail
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1; //turns the finish for that process to one
                }
            }
        }
    }
    printf("Following is the SAFE Sequence\n");
    for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n - 1]);
    return (0);
}
