#include<stdio.h>
#include<math.h>

int main(){
    int n;
    printf("Enter the order of the det:\n");//获取行列式阶数
    scanf("%d",&n);
    int a[n][n];
    long divide=1;
    long result=1;
    int counter=1;

    printf("Enter the numbers in rows:\n");//输入行列式
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<n-1;i++){//将行列式化为上三角行列式
        int temp1 = a[i][i];
        for(int j=counter++;j<n;j++)
        {
            int temp2 = a[j][i];
            for(int k=0;k<n;k++){
                a[j][k] = temp1*a[j][k] - temp2*a[i][k];
            }
        }
    }

    for(int i=0;i<n;i++){//主对角线元素相乘
        result *= a[i][i];
    }

    for(int i=0;i<n-1;i++){//除去凑整数时乘上的数字
        divide *= pow(a[i][i],n-i-1);
    }

    result /= divide;

    printf("The result is: %ld",result);

    getchar();
    getchar();

    return 0;
}