# Coding
My algorithm contest codes

Git global setup
git config --global user.name "Zry"
git config --global user.email "1214194239@qq.com"

Create a new repository
git clone git@223.3.84.218:zry/test.git
cd test
touch README.md
git add README.md
git commit -m "add README"
git push -u origin master

Push an existing folder
cd existing_folder
git init
git remote add origin git@223.3.84.218:zry/test.git
git add .
git commit -m "Initial commit"
git push -u origin master

Push an existing Git repository
cd existing_repo
git remote rename origin old-origin
git remote add origin git@223.3.84.218:zry/test.git
git push -u origin --all
git push -u origin --tags
