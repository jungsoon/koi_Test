#include<stdio.h>

int main(){

    int n, m=0, m1=0, m2=0, m3=0;

    scanf("%d",&n);

    int a[n]={0};

    for(int i=0;i<n;i++){

        scanf("%d",&a[i]);

    }

    int x,y,z; //x,y:国 z:国烹
    int sum1,sum2,sum;
    int i,j,k;

    //벌,벌,꿀통
    for(i=1;i<n;i++){
        sum1=0;
        sum2=0;
        for(j=1;j<i;j++){   //国1 ~ 国2鳖瘤
            sum1 += a[j];
        }
        for(k=j+1;k<n;k++){ //国2 ~ 国烹鳖瘤(窃膊 瘤唱皑)
            sum2 += a[k];
        }
        sum=sum2*2 + sum1;
        if(m < sum) m=sum;
    }

   // printf("%d %d\n",sum,m);

        //国烹 国1 国2
    for(i=n-2;i>=0;i--){
        sum1=0;
        sum2=0;
        for(j=0;j<i;j++){   //国烹 ~ 国1鳖瘤(窃膊 瘤唱皑)
            sum1 += a[j];
        }
        for(k=i+1;k<n-1;k++){   //国2 ~ 国1鳖瘤
            sum2 += a[k];
        }
        sum=sum1*2 + sum2;

        if(m < sum) m=sum;
    }
    //printf("%d %d\n",sum, m);

    // 国 国烹 国
    for(i=1;i<n-1;i++){ //国烹狼 困摹
        sum1=0;
        sum2=0;
        for(j=1;j<=i;j++){   //哭率 国 ~ 国烹鳖瘤狼 困摹
            sum1 += a[j];
        }
        for(k=n-2;k>=i;k--){   //坷弗率 国 ~ 国烹鳖瘤狼 困摹
            sum2 += a[k];
        }
        sum=sum1 + sum2;

        if(m < sum) m=sum;
    }

    printf("%d\n", m);

}
