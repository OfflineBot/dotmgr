# Requirements: 
The script should have read and write permission.
Its required to have the files stored in ```~/dotfiles``` like STOW
# About dotmgr (dot-manager)
Its a tool to manage files and folders. It can be a theme manager for desktops like Hyprland. 
dotmgr creates a folder at ```~/.dotmgr``` with a ```config.dot``` and a ```themes``` folder.
The themes will be saved in the themes folder and the config.dot is used for configuring which files will be saved.
### Example usage for config.dot
```
/.config/kitty
/.config/hypr
# this is a comment
/.config/hypr # this does not work!
```
# How to install:
To install run this:
```
git clone https://github.com/OfflineBot/dotmgr.git
cd dotmgr
make
```
the ```dotmgr``` file will be in ```/build/dotmgr```
