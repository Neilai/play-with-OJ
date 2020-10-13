let arr=[
    [1,1,0,1],
    [1,0,0,1],
    [0,1,0,1],
    [0,1,0,1]
]
let visited=[
    [0,0,0,0],
    [0,0,0,0],
    [0,0,0,0],
    [0,0,0,0]
]

let cnt=0
function search(map){
    for(let i=0;i<map.length;i++)
        for(let j=0;i<map[0].length;j++){
            if(!visited[i][j]&&map[i][j]!=0){
                dfs(i,j);
                cnt++; 
                console.log("!!!")
            }             
        }
}
function dfs(i,j){
    visited[i][j]=1; 
    if(i-1>=0&&!visited[i-1][j]&&arr[i-1][j]!=0)
        dfs(i-1,j);
    if(i+1<4&&!visited[i+1][j]&&arr[i+1][j]!=0)
        dfs(i+1,j);
    if(j+1<4&&!visited[i][j+1]&&arr[i][j+1]!=0)
        dfs(i,j+1);
    if(j-1>=0&&!visited[i][j-1]&&arr[i][j-1]!=0)
        dfs(i,j-1);
}
search(arr)
console.log(cnt)