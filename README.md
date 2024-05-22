This is a really simple theme manager for Linux. 
It creates a ~/.dotfiles folder with a config.dot inside to put all the dotfiles inside. 
It will create "backups" or saves in form of new folders in the ~/.dotfiles. Its just a simple copy of your setup in for example ~/.config/nvim/*. 
You can add custom your own config files inside the config.dot file. 
Each line represents a folder. 
An example would be:
```
~/.config/hypr
~/.config/nvim
~/.config/kitty
```
Its important to add the full path (for now only the folders in .config are tested).
To use the theme manager simply clone this repository. 
Build the script with cmake or just run ```make``` and go into the ```build``` folder.
To use it anywhere just set the path the the ```dotmgr``` file.
