#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n=0;
    scanf("%d",&n);
    int x=0;
    std::vector<int> blocks;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        blocks.push_back(x);
    }
    std::sort(blocks.begin(),blocks.end());
    int sums[2][1000000+1]={0};
    int curr=0;
    int prev=0;
    int actsum=0;
    for(auto b:blocks)
    {
        curr^=1;
        prev=curr^1;
        for(int j=0;j<=actsum;j++)
            sums[curr][j]=sums[prev][j];
        for(int j=0;j<actsum+1;j++)
        {
            if(!j||sums[curr][j])
            {
                if(sums[curr][j+b]<sums[prev][j]+b)
                    sums[curr][j+b]=sums[prev][j]+b;
                if(j>=b&&sums[curr][j-b]<sums[prev][j])
                    sums[curr][j-b]=sums[prev][j];
                else if(b>=j&&sums[curr][b-j]<sums[prev][j]+b-j)
                    sums[curr][b-j]=sums[prev][j]+b-j;
            }
        }
        actsum+=b;
    }
    if(!sums[curr][0])
    {
        int idx=1;
        while(!sums[curr][idx]||sums[curr][idx]==idx)idx++;
        printf("NIE\n%d",idx);
    }
    else
        printf("TAK\n%d",sums[curr][0]);
    return 0;
}
