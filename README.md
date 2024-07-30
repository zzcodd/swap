一、测试

推荐json输入：

curl -d '{ "cmd-type": "login", "username": "xhz", "password": "123"}' http://172.16.33.181:8081/apiserver/cmd

不建议使用：

curl -d "cmd-type=login&username=xhz&password=123" http://172.16.33.181:8081/apiserver/cmd

其中 172.16.33.181 需要修改为你自己的ip


二、更新代码

1. 本地自己修改和提交
$ git commit ...

2. 使用git status 来检查本地代码，不能用修改的、冲突的代码
如果本地有文件暂时还没修改完，可以使用git stash将这些没修改完的代码暂时保存到本地，就会变成没有冲突也是干净的环境

3. 下载仓库
$ git fetch origin

4. 同步代码（目前是master分支，有别的分支可使用别的分支）
$ git rebase origin/master

5. 推代码到仓库
$ git push origin/master

6. 如果做了第2步中的git stash，那这个时候需要执行 git stash pop将之前临时保存的修改提取出来，继续第1步



{"data_map":{"file_count":22,"file_list":[{"file":"20230529195219526.res.avi","folder":"20230529//.res"},{"file":"20230529195219656.near.avi","folder":"20230529//6mm"},{"file":"20230529195319625.near.avi","folder":"20230529//6mm"},{"file":"20230529195419621.near.avi","folder":"20230529//6mm"},{"file":"20230529195519608.near.avi","folder":"20230529//6mm"},{"file":"20230529195519699.res.avi","folder":"20230529//.res"},{"file":"20230529195619603.near.avi","folder":"20230529//6mm"},{"file":"size.dat","folder":"20230529/"},{"file":"20230529195230014.jpg","folder":"20230529//6mm"},{"file":"20230529195300011.jpg","folder":"20230529//6mm"},{"file":"20230529195330007.jpg","folder":"20230529//6mm"},{"file":"20230529195400003.jpg","folder":"20230529//6mm"},{"file":"20230529195430033.jpg","folder":"20230529//6mm"},{"file":"20230529195500029.jpg","folder":"20230529//6mm"},{"file":"20230529195530025.jpg","folder":"20230529//6mm"},{"file":"20230529195600021.jpg","folder":"20230529//6mm"},{"file":"20230529195630018.jpg","folder":"20230529//6mm"},{"file":"20230529195219656.near.ts","folder":"20230529//6mm"},{"file":"20230529195319625.near.ts","folder":"20230529//6mm"},{"file":"20230529195419621.near.ts","folder":"20230529//6mm"},{"file":"20230529195519608.near.ts","folder":"20230529//6mm"},{"file":"20230529195619603.near.ts","folder":"20230529//6mm"}]},"result_code":0,"result_msg":"Query success"}


{"data_map":{"file_count":16,"file_list":[{"file":"20230529195219526.res.avi","folder":"20230529//.res"},{"file":"20230529195519699.res.avi","folder":"20230529//.res"},{"file":"20230529195219656.near.avi","folder":"20230529//6mm"},{"file":"20230529195319625.near.avi","folder":"20230529//6mm"},{"file":"20230529195419621.near.avi","folder":"20230529//6mm"},{"file":"20230529195519608.near.avi","folder":"20230529//6mm"},{"file":"20230529195619603.near.avi","folder":"20230529//6mm"},{"file":"20230529195230014.jpg","folder":"20230529//6mm"},{"file":"20230529195300011.jpg","folder":"20230529//6mm"},{"file":"20230529195330007.jpg","folder":"20230529//6mm"},{"file":"20230529195400003.jpg","folder":"20230529//6mm"},{"file":"20230529195430033.jpg","folder":"20230529//6mm"},{"file":"20230529195500029.jpg","folder":"20230529//6mm"},{"file":"20230529195530025.jpg","folder":"20230529//6mm"},{"file":"20230529195600021.jpg","folder":"20230529//6mm"},{"file":"20230529195630018.jpg","folder":"20230529//6mm"}]},"result_code":0,"result_msg":"Query success"}
{"data_map":{"file_count":7,"file_list":[{"file":"20230529195219526.res.avi","folder":"20230529//.res"},{"file":"20230529195519699.res.avi","folder":"20230529//.res"},{"file":"20230529195219656.near.avi","folder":"20230529//6mm"},{"file":"20230529195319625.near.avi","folder":"20230529//6mm"},{"file":"20230529195419621.near.avi","folder":"20230529//6mm"},{"file":"20230529195519608.near.avi","folder":"20230529//6mm"},{"file":"20230529195619603.near.avi","folder":"20230529//6mm"}]},"result_code":0,"result_msg":"Query success"}
