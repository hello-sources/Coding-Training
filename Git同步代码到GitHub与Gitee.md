# Git同步代码到GitHub与Gitee仓库中

- 先删除已经关联的origin的远程库

``` shell
git remote rm origin
```

- 关联GitHub与Gitee远程库

``` shell
//GitHub按照Coding-Training仓库为例
git remote add git@github.com:hello-sources/Coding-Training.git
//Gitee按照Coding-Training仓库为例
git remote add git@gitee.com:hello-sources/Coding-Training.git
```

- 配置同步方式

```shell
//修改每个仓库中.git文件夹中的config文件，修改如下，修改前
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
[remote "origin"]
    url = git@github.com:hello-sources/Coding-Training.git
    fetch = +refs/heads/*:refs/remotes/github/*
[branch "master"]
    remote = origin
    merge = refs/heads/master
    
//修改后
[core]
    repositoryformatversion = 0
    filemode = true
    bare = false
    logallrefupdates = true
[remote "github"]
    url = git@github.com:hello-sources/Coding-Training.git
    fetch = +refs/heads/*:refs/remotes/github/*
[remote "gitee"]
    url = git@gitee.com:hello-sources/Coding-Training.git
    fetch = +refs/heads/*:refs/remotes/github/*
[branch "master"]
    remote = origin
    merge = refs/heads/master
```

其实很好理解，就是在使用`git push origin master`命令的时候把对应的`origin`关键字换成对应的`GitHub`与`Gitee`关键字，而对应关键字对应不同仓库的URL，这样就能把代码同步到GitHub与Gitee中了。

- 查看远程库

使用`git remote -v`可以查看远程库信息

```shell
gitee   git@github.com:hello-sources/Coding-Training.git (fetch)
gitee   git@github.com:hello-sources/Coding-Training.git (push)
github  git@github.com:hello-sources/Coding-Training.git (fetch)
github  git@github.com:hello-sources/Coding-Training.git (push)
```

- 上传代码

```shell
git add "你要上传的代码"   或者使用git add .(来保持最近更新)
git commit -m "填写此部分代码更新的内容"
```

- 提交代码到`Github`

```shell
git push github master
```

- 提交代码到`Gitee`

```shell
git push gitee master
```



 #  Bingo!

