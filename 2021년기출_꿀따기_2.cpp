#include<stdio.h>

int main(){

    int n, m=0, m1=0, m2=0, m3=0;

    scanf("%d",&n);

    int a[n]={0};

    for(int i=0;i<n;i++){

        scanf("%d",&a[i]);

    }

    int x,y,z; //x,y:�� z:����
    int sum1,sum2,sum;
    int i,j,k;

    //���� ����
    for(i=1;i<n;i++){
        sum1=0;
        sum2=0;
        for(j=1;j<i;j++){   //
            sum1 += a[j];
        }
        for(k=j+1;k<n;k++){
            sum2 += a[k];
        }
        sum=sum2*2 + sum1;
        if(m < sum) m=sum;
    }

   // printf("%d %d\n",sum,m);

        //���� �� ��
    for(i=n-2;i>=0;i--){
        sum1=0;
        sum2=0;
        for(j=0;j<i;j++){   //
            sum1 += a[j];
        }
        for(k=i+1;k<n-1;k++){
            sum2 += a[k];
        }
        sum=sum1*2 + sum2;

        if(m < sum) m=sum;
    }
    //printf("%d %d\n",sum, m);

    // �� ���� ��
    for(i=1;i<n-1;i++){ //������ ��ġ
        sum1=0;
        sum2=0;
        for(j=1;j<=i;j++){   //���� �� ~ ��������� ��ġ
            sum1 += a[j];
        }
        for(k=n-2;k>=i;k--){   //������ �� ~ ��������� ��ġ
            sum2 += a[k];
        }
        sum=sum1 + sum2;

        if(m < sum) m=sum;
    }

    printf("%d %d\n",sum, m);


}
