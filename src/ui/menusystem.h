// menusystem.h
//
// (c) Robert Schuster, 2007
//
// Licensed under GNU GPL version 2 or, at your option, any later version.

#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include <map>

#include "guichan/guichan.hpp"
#include "guichan/guichan/sdl.hpp"

#include "menu.h"

/**
 * MenuSystem cares for all the low-level interaction of the menu system with
 * guichan.
 *
 * It is only supposed to be called through MenuManager.
 */
class MenuSystem
{
  class KeyListener : public gcn::KeyListener
  {
    MenuSystem &system;

    public:
    KeyListener(MenuSystem &menuSystem);

    virtual void keyReleased(gcn::KeyEvent &);
  };

  gcn::Gui *gui;

  gcn::ImageFont *normal;
  gcn::ImageFont *highlighted;

  gcn::Container *top;

  std::map< Menu::Id, Menu * > *menus;

  Menu *currentMenu, *nextMenu;

  KeyListener *menuKeyListener;

  static gcn::ImageFont *loadFont(std::string);

  static gcn::Image *loadImage(std::string);

  public:
    MenuSystem(gcn::SDLInput *);
    ~MenuSystem();

    void render();

    bool update();

    void resize();

    void addMenu(Menu::Id, Menu *);

    void enter(Menu::Id = Menu::MAIN);

    /** Cancels whatever operation is currently in progress.
     * 
     * At the moment the following operations are known:
     * <ul>
     * <li>A widget may have initiated the input sensing mode. If it is
     * canceled the input mapping will not change.</li>
     * 
     * <li>A certain submenu is open. On canceling it will get close and
     * enter its parent menu.</li>
     * 
     * <li>The main menu is open. On canceling it will be hidden.</li> 
     */  
    void cancel();

    void invoke();

    bool isVisible() const;

    gcn::ImageFont *getNormalFont();

    gcn::ImageFont *getHighlightedFont();
};

#endif
