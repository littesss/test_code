
github：是一个面向开源并且私有软件的一个托管平台，国内不必翻墙就可以进入
github：有趣的故事
2013年1月15日晚间，全球最大的社交编程及代码托管网站GitHub突然疑似遭遇DDOS攻击，访问大幅放缓，该网站管理员经过日志查询，发现是来自12306的抢票插件用户洪水般的访问导致GitHub出现问题。
2013年1月20日左右，GitHub在中国大陆被官方的防火长城封锁（封锁手段为域名污染和关键词过滤），李开复等一些微博大号呼吁解禁GitHub，微博转发近10万条。2013年1月23日github网站恢复正常访问。
///////////////////////////////////////////////////////////////////////
1. 首先在www.github.com 上注册一个人账号
2. 在github上开启一个项目

//////在Ubuntu上
1. 首先安装 git
sudo apt install git
2. 把自己托管在github上的项目克隆（clone）一份到本地
sudo git  clone http://www.github.com/***/****     

3. 配置你的username   和 email
sudo config  user.username --global "yourname"          (yourname，填你自己的名字)
sudo config user.email --global "youremai@.163.com"  

4
 本地就多了一个目录是你github上的项目
然后你就可以进入里面在linux上面进行代码填充，

5. git 添加代码
git add .                      (此时,代表所有)

6. git 提交代码
sudo git  commit  -m "this is my first commit!"

7. 推到远端（github上面）
git push
注意：首次推送的时候会出现match之类的提示
a，一律回车
b，.此时选着simple那个配置
  git config --global push.default simple

8. 就可以push到github上面
  git push

9. 输入github账号：你自己在github上的账号
10. 输入github密码： 你自己github上的密码
11. 所有步骤完毕：可以进入www.github.com上面，进入到自己的github上可以看到自己添加的代码了



////////////////////////////////////////////////////////////////////////////////////
如果想要下载别人的项目
git  clone        ****************
/////////////////////////////////////////////////////////////////////////////////////
  如果想要加入开源项目
  1, 进入别人的项目 ，在github上面
  2.点击fork
  3.进入 自己的github ，就会多了一个项目
  4.然后自己在Linux上clone
  5.给开源项目添砖加瓦
  6.git push 到github上
  7.new pull request
  8.pull request ,添上你要提交的原因以及理由，
  9,.就看开源项目发起人是否接纳自己的request
  ///////////////////////////////////////////////////////////////////////////////////
  github真的是个好东西，你自己可以search 你自己所感兴趣的项目，进行学习！！！！！！！！
#####

git commit -am "***" // -a是修改了目录
要查看删除的文件： git ls-files --deleted
E
使用命令checkout来恢复：git checkout -- file_name


//github出现的问题
1. lsh@ubuntu:~/git/code$ git push
    fatal: You are not currently on a branch.
    To push the history leading to the current (detached HEAD)
    state now, use
    git push origin HEAD:<name-of-remote-branch>
解决：
git push origin HEAD:master --force 

