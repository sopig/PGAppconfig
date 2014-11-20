idea
====

Knowledge points summary

注册 GitHub 后你就会有 0.3G 的免费空间,不过只能创建公开项目, 这也满足代码分享的目的,我最喜欢的倒是它的代码展示方式,可以 直接浏览你的代码,代码是经过高亮、添加行号处理过的,十分漂亮, 体验一流,比如这个 Webpy 托管的地方。而作为想要了解你代码的 人,可以选择直接在线浏览自己感兴趣的,也可以直接下载压缩包, 或者直接使用 Git clone 到本地。
因为 GitHub 是基于 Git 版本控制系统,所以你上传修改代码什么的, 都需要使用 Git 工具。我这里主要是用来分享和展示代码,所以不想 在版本控制方面做过多的阐述,下面就简单讲解一下怎么在 GitHub 上新建一个项目,还有把自己的代码传上去。下面的前提是你已经注 册了 GitHub 和下载安装了 Git——Git 下载、Windows 版本下载。 上传分享代码
1.在 GitHub 上建立项目
登录 GitHub 后,你可以在右边靠中那里找到一个按钮“New Repository”,点击过后,填入项目名称、说明和网址过后就可以创 建了,然后会出现一个提示页面,记下类似 git@github.com:XXX/XXX.git 的地址,这个就是你这个项目的地址了。 2.配置 Git 以及上传代码
安装 Git 成功后,如果是 Windows 下,选择 Git Bash,在命令行中完 成一切,可能开始有点麻烦,不过就那几条命令行,用几次就记住啦。 首先初始设置 Git:
1 git config --global user.name "Your Real Name" 2 git config --global
user.email you@email.address
然后开始进行最麻烦的一步了,你需要上传文件到 GitHub 的 Git 系 统上,得需要一个 SSH 密匙来认证,下面就开始生成密钥和提交密 钥。打开 Git Bash,创建 SSH key:
1 ssh-keygen -C 'your@email.address' -t rsa
然后要你输入 SSH 密匙的存放位置,可以不管,直接回车使用默认 路径。再输入你想要的密码,SSH key 就生成了。现在你需要将这个 Key提交到GitHub,首先打开Key保存的位置,里面会有三个文件, 找到 id_rsa.pub,用文本编辑器打开,复制里面的全部字符。到 GitHub, 在右上方工具栏里找到Account Settings。在这个页面上有一个SSH Public Keys 标签,选择 Add another public key。Title 可以随便填一 个,Key 就粘贴刚才的字符,提交。 完成这些工作后,就可以上传自己的代码了。找到自己要分享上传的 代码文件夹,右击选择 Git Bash,或者在 Git Bash 中进入这个文件夹。 建立一个仓库:
1 git init
选择要添加进仓库的文件:
1 git add .
一般如果你想分享这个文件夹里的所有代码,就在 add 后面加“.”, 上面的例子就是这样,如果传指定的,只需要把“.”改为文件名即 可,现在只是选择了要加入仓库的文件,下面才是添加进入仓库:
1 git commit -m 'Test'
-m 后面跟一个参数,表示说明,将代码提交到 GitHub 后,将会在代 码文件信息上显示这个说明,如下图标记的地方。 搞了这么久,现在才开始把本地仓库上传到 GitHub 了,下面两行命 令搞定问题:
1 2 git remote add origin git@github.com:XXX/XXX.git 3 git push -u origin master
这个 git@github.com:XXX/XXX.git 就是上面创建项目是生成的地址。 现在打开你的项目网址,你就可以发现你的代码已经展示出来了。如 果你要更新代码的话,就重复上面的吧。 如果提交了敏感信息,比如代码中设置的自己的密码什么的忘删除就 上传上去了怎么办?重新修改过后上传依然有历史记录,而使用 Git 删除历史记录貌似很麻烦,于是就采用删除项目吧,删除了再重新上 传。删除项目需要在 GitHub 网站上右上方找到 admin 按钮,进去后 右边最下面有个删除的按钮,这样就可以删除了。 一些可能遇到的问题解决:
如果输入$ git remote add origin git@github.com:djqiang(github 帐
号名)/gitdemo(项目名).git
提示出错信息:fatal: remote origin already exists.
解决办法如下:
1、先输入$ git remote rm origin
2、再输入$ git remote add origin git@github.com:djqiang/gitdemo.git 就不会报错了!
3、如果输入$ git remote rm origin 还是报错的话,error: Could not remove config section ‘remote.origin’. 我们需要修改 gitconfig 文 件的内容
4 、找到你的 github 的安装路径,我的是 C:\Users\ASUS\AppData\Local\GitHub\PortableGit_ca477551eeb4a ea0e4ae9fcd3358bd96720bb5c8\etc
5、找到一个名为 gitconfig 的文件,打开它把里面的[remote "origin"] 那一行删掉就好了!
如果输入$ ssh -T git@github.com
出现错误提示:Permission denied (publickey).因为新生成的key不 能加入 ssh 就会导致连接不上 github。
解决办法如下:
1、先输入$ ssh-agent,再输入$ ssh-add ~/.ssh/id_key,这样就可以 了。
2、如果还是不行的话,输入 ssh-add ~/.ssh/id_key 命令后出现报错 Could not open a connection to your authentication agent.解决方法
是key用Git Gui的ssh工具生成,这样生成的时候key就直接保存 在 ssh 中了,不需要再 ssh-add 命令加入了,其它的 user,token 等 配置都用命令行来做。
3、最好检查一下在你复制 id_rsa.pub 文件的内容时有没有产生多余 的空格或空行,有些编辑器会帮你添加这些的。
如果输入$ git push origin master
提示出错信息:error:failed to push som refs to ....... 解决办法如下:
1、先输入$ git pull origin master //先把远程服务器 github 上面的文 件拉下来
2、再输入$ git push origin master
3、如果出现报错 fatal: Couldn’t find remote ref master 或者 fatal: ‘origin’ does not appear to be a git repository 以及 fatal: Could not read from remote repository.
4 、则需要重新输入 $ git remote add origingit@github.com:djqiang/gitdemo.git
使用 git 在本地创建一个项目的过程
$ makdir ~/hello-world //创建一个项目 hello-world
$ cd ~/hello-world $ git init
$ touch README
$ git add README
//打开这个项目 //初始化
//更新 README 文件
$ git commit -m ‘first commit’ //提交更新,并注释信息“first commit”
$ git remote add origin git@github.com:defnngj/hello-world.git //连接远程 github 项目
$ git push -u origin master //将本地项目更新到github项目上 去


