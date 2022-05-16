#include <stdio.h>
int w[5][7][4];
int c[7][4];
int chk[5];

int check(int num)
{
 int chk=0, i, j;
 for(i=1;i<=6;i++) {
  for(j=1;j<=3;j++) {
   if(c[i][j]!=w[num][i][j]) {
    return 0;
   }
  }
 }
 return 1;
}

void world(int a, int b)
{
 int i;
 if(b>6) {
  a++;
  b=a+1;
 }
 if(a==6) {
  for(i=1;i<=4;i++) {
   if(chk[i]==0) chk[i]=check(i);
  }
  return;
 }
 c[a][1]++;  c[b][3]++;
 world(a,b+1);
 c[a][1]--;  c[b][3]--;

 c[a][2]++; c[b][2]++;
 world(a,b+1);
 c[a][2]--;  c[b][2]--;

 c[a][3]++;  c[b][1]++;
 world(a,b+1);
 c[a][3]--;  c[b][1]--;
}

int main()
{
 int i,j,k;
 FILE *fin = fopen("INPUT.TXT","r");
 for(i=1;i<=4;i++) {
  for(j=1;j<=6;j++) {
   for(k=1;k<=3;k++) {
    fscanf(fin,"%d",&w[i][j][k]);
   }
  }
 }
 fclose(fin);
 world(1,2);
 FILE*fout=fopen("OUTPUT.TXT","w");
 fprintf(fout,"%d %d %d %d",chk[1],chk[2],chk[3],chk[4]);
 fclose(fout);
 return 0;
}
