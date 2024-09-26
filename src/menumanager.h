// menumanager.h
//
// (c) Robert Schuster, 2007
//
// Licensed under GNU GPL version 2 or, at your option, any later version.

#ifndef MENUMANAGER_H
#define MENUMANAGER_H

class Main;

class ControlOptions;
class VideoOptions;
class GameOptions;

class MenuSystem;
class MenuAction;
class MenuManager
{
  Main &main;

  ControlOptions *controlOptions;
  VideoOptions *videoOptions;
  GameOptions *gameOptions;

  MenuSystem *menuSystem;

  public:
    MenuManager(Main &);

    ~MenuManager();

    void showSinglePlayerMenu();
    void show();
    void hide();
    bool isVisible() const;

    void resize();

    void render();

    bool update();

    void senseFinished(bool);

    GameOptions &getGameOptions() const { return *gameOptions; };

    VideoOptions &getVideoOptions() const { return *videoOptions; };
};

class QuitAction;

#endif
