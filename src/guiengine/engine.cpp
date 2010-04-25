//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2009 Marianne Gagnon
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

/**
 
 
 \page gui_overview GUI Module Overview
 
 In XML files, widgets are declared in the following fashion :
 
 \code
 <widget_name property1="value1" property2="value2" />
 \endcode
 
 or, for widgets of "spawn" type, with children :
 
 \code
 <widget_name property1="value1" property2="value2" />
 <child1 />
 <child2 />
 </widget_name>
 \endcode
 
 The first section of this document describes the widgets you can use; the second describes the properties
 widgets can take. Not all properties can be applied to all widgets, see the docs for a given widget and a
 given property for full information.
 
 \section toc Table of Contents
 \ref widgets
 \li \ref widget1
 \li \ref widget2
 \li \ref widget3
 \li \ref widget4
 \li \ref widget5
 \li \ref widget6
 \li \ref widget7
 \li \ref widget8
 \li \ref widget9
 \li \ref widget10
 \li \ref widget11

 \ref props
 \li \ref prop1
 \li \ref prop2
 \li \ref prop3
 \li \ref prop4
 \li \ref prop5
 \li \ref prop6
 \li \ref prop7
 \li \ref prop8
 \li \ref prop9
 \li \ref prop10
 \li \ref prop11
 \li \ref prop12
 \li \ref prop13
 \li \ref prop14
 \li \ref prop15
 \li \ref prop16
 \li \ref prop17
 \li \ref prop18

 \ref code
 
 \n
 \n
 \section widgets Widgets
 
 This section describes the widgets you can use in STK's GUI XML files. The upper-case name starting with
 WTYPE_* is the internal name of the widget  (see the GUIEngine::WidgetType enum).
 
 
 \subsection widget1 WTYPE_RIBBON
 <em> Names in XML files: </em> \c "ribbon", \c "buttonbar", \c "tabs" 
 
 Appears as an horizontal bar containing elements laid in a row, each being and icon and/or a label
 
 \li The "ribbon" subcategory will behave a bit like a radio button group, i.e. one element must selected.
 events are triggered as soon as a choice is selected (can be simply by hovering).
 \li The "buttonbar" subcategory treats children buttons as action buttons, which means they can't have a
 'selected' state, only focused or not (i.e. there is no selection that remains if you leave this area).
 events are triggered only on enter/fire.
 \li The "tabs" subcategory will show a tab bar. behaviour is same as normal ribbon, only looks are different.
 Orientation of tabs (up or down) is automatically inferred from on-screen position
 
 \note Ribbon widgets are of spawn type (\<ribbon\> ... \</ribbon\>) and may contain icon-buttons or buttons as children.
 \note Property PROP_SQUARE can be set to tell the engine if the ribbon's contents are rectangular or not (this will
 affect the type of highlighting used)
 \note All elements within a ribbon must have an 'ID' property
 
 \n
 \subsection widget2 WTYPE_SPINNER
 Names in XML files: </em> \c "spinner", \c "gauge"
 
 A spinner component (lets you choose numbers).
 
 Specify PROP_MIN_VALUE and PROP_MAX_VALUE to have control over values (default will be from 0 to 10).
 You can specify an icon; then, include a sprintf format string like %i in the name, and at runtime the
 current number will be inserted into the given name to find the
 right file for each possible value the spinner can take. It may also display arbitrary text instead of
 numbers, though this cannot be achieve in the XML file; use the -\>addLabel(...) method in code to do this.
 It can also display arbitrary text containing the value; just define the PROP_TEXT property to contain
 the text you want, including a format string %i where the value should appear.
 \note The "gauge" variant behaves similarly, but a fill band shows how close to the max the value is.
 
 \n
 \subsection widget3 WTYPE_BUTTON
 <em> Name in XML files: </em> \c "button" 
 
 A plain text button.
 
 \n
 \subsection widget4 WTYPE_ICON_BUTTON
 <em> Names in XML files: </em> \c "icon-button", \c "icon" 
 
 A component with an image, and optional text to go under it.
 
 \note The "icon" variant will have no border and will not be clickable. PROP_ICON is mandatory for this component.
 There are three ways to place the texture within the allocated space; the default (and only way currently accessible
 through xml files) is to scale the texture to fit, while preserving its aspect ratio; other methods, currently only
 accessible through C++ code, are to stretch the texture to fill the area without caring for aspect ratio, and another
 to respect an aspect ratio other than the texture's (useful for track screenshots, which are 4:3 compressed to fit
 in a power-of-two 256x256 texture)
 
 \n
 \subsection widget5 WTYPE_CHECKBOX
 <em> Name in XML files: </em> \c "checkbox" 
 
 A checkbox.
 
 \n
 \subsection widget6 WTYPE_LABEL
 <em> Names in XML files: </em> \c "label", \c "header" 
 
 A plain label.
 
 Supports properties PROP_WORD_WRAP and PROP_TEXT_ALIGN.
 \note The "Header" variant uses a bigger and more colourful font.
 
 \n
 \subsection widget7 WTYPE_SPACER
 <em> Name in XML files: </em> \c "spacer" 
 
 Some blank space; not visible on screen.
 
 \n
 \subsection widget8 WTYPE_DIV
 <em> Name sin XML files: </em> \c "div", \c "box" 
 
 An invisible container.
 
 \li Divs do not do much on themselves, but are useful to lay out children automatically (Supports property PROP_LAYOUT)
 \li Divs can be nested.
 \li Of spawn type (\<div\>...\</div\>, place children within)
 \note "box" is a variant that acts exactly the same but is visible on-screen
 
 \n
 \subsection widget9 WTYPE_DYNAMIC_RIBBON
 Names in XML files: </em> \c  "ribbon_grid", \c "scrollable_ribbon", \c "scrollable_toolbar"
 
 Builds upon the basic Ribbon to be more dynamic (dynamics contents, possibly with scrolling, possibly multi-line)
 
 \li NOT of spawn type (\<ribbon_grid .../\>), i.e. children are not specified in the XML file but
 programmatically at runtime.
 \li PROP_CHILD_WIDTH and PROP_CHILD_HEIGHT are mandatory (so at least aspect ratio of elements that will later be
 added is known) An interesting aspect of PROP_CHILD_WIDTH and PROP_CHILD_HEIGHT is that you can use them to
 show textures to any aspect ratio you want (so you can e.g. save textures to a power-of-two size like 256x256,
 but then show it in 4:3 ratio).
 \li Property PROP_SQUARE can be set to tell the engine if the ribbon's contents are rectangular or icons (this will
 affect the type of highlighting used).
 \li Supports an optional label at the bottom if PROP_LABELS_LOCATION is set (see more on PROP_LABELS_LOCATION below).
 \note The "scrollable_ribbon" and "scrollable_toolbar" subtypes are single-line scrollable ribbons.
 The difference between both is that 'scrollable_ribbon' always has a value selected (like in
 a combo box, or radio buttons), while 'scrollable_toolbar' is a scrollable list of buttons that can be
 pressed to trigger actions.
 
 \n
 \subsection widget10 WTYPE_MODEL_VIEW
 <em> Name in XML files: </em> \c "model" 
 
 Displays a 3D model.
 
 \note Contents must be set programmatically.
 
 \n
 \subsection widget11 WTYPE_LIST
 <em> Name in XML files: </em> \c "list" 
 
 Displays a list.
 
 \note Contents must be set programmatically.
 
 
 \n
 \n
 \section props Properties
 
 \subsection prop1 PROP_ID
 <em> Name in XML files: </em> \c "id" 
 
 Gives a unique internal name to each object using this property. It will be
 used in events callbacks to determine what action occurred. Can be omitted
 on components that do not trigger events (e.g. labels)
 
 \n
 \subsection prop2 PROP_TEXT
 <em> Name in XML files: </em> \c "text" 
 
 gives text (a label) to the widget where supported. Ribbon-grids give a special meaning
 to this parameter, see ribbon-grid docs above.
 
 \n
 \subsection prop3 PROP_ICON
 <em> Name in XML files: </em> \c "icon" 
 
 give an icon to the widget. Property contents is the path to the file, by default relative
 relative to the /data directory of STK (several methods of IconButtonWidget and DynamicRibbon
 can enable you to use absolute paths if you wish, however).
 
 \n
 \subsection prop4 PROP_TEXT_ALIGN
 <em> Name in XML files: </em> \c "text_align" 
 
 used exclusively by label components. Value can be "right" or "center" (left used if not specified).
 
 \n
 \subsection prop5 PROP_WORD_WRAP
 <em> Name in XML files: </em> \c "word_wrap" 
 
 used exclusively by label components. Value can be "true" to indicate that long text should spawn on
 multiple lines.
 
 \n
 \subsection prop6 PROP_MIN_VALUE, PROP_MAX_VALUE
 <em> Name in XML files: </em> \c "min_value", \c "max_value" 
 
 used to specify a minimum and maximum value for numeric widgets (c.f. spinner)
 
 \n
 \subsection prop7 PROP_X, PROP_Y       
 <em> Name in XML files: </em> \c "x", "y" 
 
 sets the position (location) of a widget, relative to its parent (container \<div\> or screen if none).
 A plain number will be interpreted as an aabsolute position in pixels. A '%' sign may be added to the
 given number to mean that the location is specified in terms of a percentage of parent size (parent size
 means the parent \<div\> or the whole screen if none). A negative value can also be passed to start coordinate
 from right and/or bottom, instead of starting from top-left corner as usual.
 Note that in many cases, it is not necessary to manually a position. Div layouts will often manage that
 for you (see PROP_LAYOUT). Other widgets will also automativally manage the position and size of their children,
 for instance ribbons.
 
 \n
 \subsection prop8 PROP_WIDTH, PROP_HEIGHT       
 <em> Name in XML files: </em> \c "width", \c "height" 
 
 give dimensions to the widget. A plain number will be interpreted as an aabsolute position in pixels.
 A '%' sign may be added to the given number to mean that the size is specified in terms of a percentage
 of parent size (parent size means the parent \<div\> or the whole screen if none).
 Note that in many cases, it is not necessary to manually a size. Div layouts will often manage that
 for you (see PROP_LAYOUT). In addition, sizes are automatically calculated for widgets made of icons
 and/or text like labels and plain icons. Other widgets will also automativally manage the position and
 size of their children, for instance ribbons.
 
 \n
 \subsection prop9 PROP_MAX_WIDTH, PROP_MAX_HEIGHT    
 <em> Names in XML files: </em> \c "max_width", \c "max_height" 
 
 The maximum size a widget can take; especially useful when using percentages and proportions.
 
 \n
 \subsection prop10 PROP_CHILD_WIDTH, PROP_CHILD_HEIGHT
 <em> Names in XML files: </em> \c "child_width", \c "child_height" 
 
 Used exclusively by the ribbon grid widget. See docs for this widget above.
 
 \n
 \subsection prop11 PROP_LAYOUT
 <em> Name in XML files: </em> \c "layout"
 
 Valid on 'div' containers. Value can be "horizontal-row" or "vertical-row". This means x and y coordinates
 of all children will automatically be calculated at runtime, so they are laid in a row. Width and height can
 be set absolutely as usual, but can also be determined dynamically according to available screen space. Also
 see PROP_ALIGN and PROP_PROPORTION to known more about controlling layouts. Note that all components within a
 layed-out div will ignore all x/y coordinates you may give them as parameter.
 
 \n
 \subsection prop12 PROP_ALIGN
 <em> Name in XML files: </em> \c "align" 
 
 For widgets located inside a vertical-row layout div : Changes how the x coord of the widget is determined.
 value can be \c "left", \c "center" or \c "right".
 
 For widgets located inside a horizontal-row layout div : Changes how the y coord of the widget is determined.
 value can be \c "top", \c "center" or \c "bottom".
 
 \n
 \subsection prop13 PROP_PROPORTION
 <em> Name in XML files: </em> \c "proportion"
 
 Helps  determining widget size dynamically (according to available screen space) in layed-out divs. In a
 vertical row layout, proportion sets the height of the item. In an horizontal row, it sets the width of
 the item. Proportions are always evaluated relative to the proportions of other widgets in the same div.
 If one div contains 4 widgets, and their proportions are 1-2-1-1, it means the second must take twice as
 much space as the 3 others. In this case, 10-20-10-10 would do the exact same effect. 1-1-1-1 would mean
 all take 1/4 of the available space. Note that it is allowed to mix absolute widget sizes and proportions;
 in this case, widgets with absolute size are evaluated first, and the dynamically-sized ones split the
 remaining space according to their proportions.
 
 \n
 \subsection prop14 PROP_SQUARE
 <em> Name in XML files: </em> \c "square_items"
 
 Valid on Ribbons or RibbonGrids. Can be "true" (omitting it means "false"). Indicates whether the contents
 use rectangular icons as opposed to "round" icons (this will affect the type of focus/highlighting used)
 
 \n
 \subsection prop15 PROP_EXTEND_LABEL
 <em> Name in XML files: </em> \c "extend_label"
 
 How many pixels the label is allowed to expand beyond the boundaries of the widget itself. Currently only
 allowed on icon widgets.
 
 \n
 \subsection prop16 PROP_LABELS_LOCATION
 <em> Name in XML files: </em> \c "label_location"
 
 Currently only used by dynamic ribbons. Decides where the label is. Value can be "each", "bottom", or "none"
 (if ommitted, "none" is the default). "each" means that every item has its own label. "bottom" means there
 is a single label for all at the bottom, that displays the name of the current item.
 
 \n
 \subsection prop17 PROP_MAX_ROWS
 <em> Name in XML files: </em> \c "max_rows" 
 
 Currently used for ribbon grids only. Indicates the maximum amount of rows this ribbon can have.
 
 \n
 \subsection prop18 PROP_WARP_AROUND
 <em> Name in XML files: </em> \c "warp_around" 
 
 Currently used for spinners only. Value can be "true" or "false"
 
 
 \n
 \section code Using the engine in code
 
 The first thing to do is to derive a class of your own from AbstractStateManager. There are a few callbacks
 you will need to override. Once it's done, you have all AbstractStateManager methods ready to be used to
 push/pop/set menus on the screen stack.
 Once you have instanciated your state manager class, call GUIEngine::init and pass it as argument.
 One of the most important callbacks is 'eventCallback', which will be called everytime sometimes happens.
 Events are generally a widget state change. In this case, a pointer to the said widget is passed along its
 name, so you get its new state and/or act.
 
 When you have described the general layout of a Screen in a XML file, as described above, you may use it
 in the code by creating a class deriving from GUIEngine::Screen, passing the name of the XML file to the
 constructor of the base class. The derived class will most notably be used for event callbacks, to allow
 creating interactive menus. The derived class must also implement the GUIEngine::Screen::init and
 GUIEngine::Screen::tearDown methods, that will be called, respectively, when a menu is entered/left. For
 simple menus, it is not unexpected that those methods do nothing.
 
 Note that the same instance of your object may be entered/left more than once, so make sure that one instance
 of your object can be used several times if the same screen is visited several times.
 
 You can also explore the various methods in GUIEngine::Screen to discover more optional callbacks you
 can use.
 
 You can also create dialogs by deriving from GUIEngine::ModalDialog. Unfortunately, it is currently not
 possible to specify modal dialogs through XML files (FIXME), so you will need to simulate the init
 sequence of a GUI screen, which I admit is not too easy. This is to improve in the future.
 
 */

#include "guiengine/engine.hpp"

#include <iostream>
#include <assert.h>

#include "io/file_manager.hpp"
#include "input/input_manager.hpp"
#include "guiengine/CGUIFont.h"
#include "guiengine/event_handler.hpp"
#include "guiengine/modaldialog.hpp"
#include "guiengine/screen.hpp"
#include "guiengine/skin.hpp"
#include "guiengine/widget.hpp"
#include "modes/world.hpp"

using namespace irr::gui;
using namespace irr::video;

namespace GUIEngine
{

    namespace Private
    {
        IGUIEnvironment* g_env;
        Skin* g_skin = NULL;
        IGUIFont* g_font;
        IGUIFont* g_title_font;
        IGUIFont* g_small_font;
        
        IrrlichtDevice* g_device;
        IVideoDriver* g_driver;
        Screen* g_current_screen = NULL;
        AbstractStateManager* g_state_manager = NULL;
        Widget* g_focus_for_player[MAX_PLAYER_COUNT];
        
        int font_height;
        int small_font_height;
    }
    using namespace Private;
   
    ptr_vector<Widget, REF> needsUpdate;
    
    //FIXME: the contents of this vector are never ever freed
    ptr_vector<Screen, REF> g_loaded_screens;

    float dt = 0;
    
    float getLatestDt()
    {
        return dt;
    }
    
    struct MenuMessage
    {
        irr::core::stringw m_message;
        float m_time;
        
        MenuMessage(const wchar_t* message, const float time) : m_message(message), m_time(time)
        {
        }
    };
    std::vector<MenuMessage> gui_messages;
    
    void showMessage(const wchar_t* message, const float time)
    {
        gui_messages.push_back( MenuMessage(message, time) );
    }
    
    Widget* getFocusForPlayer(const int playerID)
    {
        assert(playerID >= 0);
        assert(playerID < MAX_PLAYER_COUNT);
        
        return g_focus_for_player[playerID];
    }
    void focusNothingForPlayer(const int playerID)
    {
        Widget* focus = getFocusForPlayer(playerID);
        if (focus != NULL) focus->unsetFocusForPlayer(playerID);
        
        g_focus_for_player[playerID] = NULL;
    }
    bool isFocusedForPlayer(const Widget* w, const int playerID)
    {
        assert(w != NULL);
        assert(playerID >= 0);
        assert(playerID < MAX_PLAYER_COUNT);
        
        // If no focus
        if (g_focus_for_player[playerID] == NULL) return false;
        
        // otherwise check if the focus is the given widget
        return g_focus_for_player[playerID]->isSameIrrlichtWidgetAs(w);
    }
       
    int getFontHeight()
    {
        return Private::font_height;
    }
    
    int getSmallFontHeight()
    {
        return Private::small_font_height;
    }
    
// -----------------------------------------------------------------------------  
void clear()
{
    g_env->clear();
    if (g_current_screen != NULL) g_current_screen->elementsWereDeleted();
    g_current_screen = NULL;
}
// ----------------------------------------------------------------------------- 
    
void cleanForGame()
{
    clear();
    
    //FIXME: I'm not very sure why this isn't called in the regular clear() method??
    needsUpdate.clearWithoutDeleting();
}
    
// -----------------------------------------------------------------------------  
void switchToScreen(const char* screen_name)
{    
    needsUpdate.clearWithoutDeleting();
    
    // clean what was left by the previous screen
    g_env->clear();
    if (g_current_screen != NULL) g_current_screen->elementsWereDeleted();
    g_current_screen = NULL;
    Widget::resetIDCounters();
    
    // check if we already loaded this screen
    const int screen_amount = g_loaded_screens.size();
    for(int n=0; n<screen_amount; n++)
    {
        if (g_loaded_screens[n].getName() == screen_name)
        {
            g_current_screen = g_loaded_screens.get(n);
            break;
        }
    }
    
    // screen not found in list of existing ones, so let's create it
    if (g_current_screen == NULL)
    {
        assert(false);
        return;
        //GUIEngine::Screen* new_screen = new GUIEngine::Screen(screen_name);
        //g_loaded_screens.push_back(new_screen);
        //g_current_screen = new_screen;
    }
    
    
    // show screen
    g_current_screen->addWidgets();
}
// -----------------------------------------------------------------------------
    
void addScreenToList(Screen* cutscene)
{
    g_loaded_screens.push_back(cutscene);
}
    
// -----------------------------------------------------------------------------

void reshowCurrentScreen()
{
    needsUpdate.clearWithoutDeleting();
    g_state_manager->reshowTopMostMenu();
    //g_current_screen->addWidgets();
}
    
// -----------------------------------------------------------------------------
void cleanUp()
{
    if (g_skin != NULL) delete g_skin;
    g_skin = NULL;
    for (int i=0; i<g_loaded_screens.size(); i++)
    {
        g_loaded_screens[i].forgetWhatWasLoaded();
    }
    
    g_current_screen = NULL;
    needsUpdate.clearWithoutDeleting();
    
    if (ModalDialog::isADialogActive()) ModalDialog::dismiss();

    delete g_font;
    g_font = NULL;
    delete g_title_font;
    g_title_font = NULL;
    delete g_small_font;
    g_small_font = NULL;
        
    // nothing else to delete for now AFAIK, irrlicht will automatically kill everything along the device
}
    
// -----------------------------------------------------------------------------
void init(IrrlichtDevice* device_a, IVideoDriver* driver_a, AbstractStateManager* state_manager )
{
    g_env = device_a->getGUIEnvironment();
    g_device = device_a;
    g_driver = driver_a;
    g_state_manager = state_manager;
    
    for (int n=0; n<MAX_PLAYER_COUNT; n++)
    {
        g_focus_for_player[n] = NULL;
    }
    
    /*
     To make the g_font a little bit nicer, we load an external g_font
     and set it as the new default g_font in the g_skin.
     To keep the standard g_font for tool tip text, we set it to
     the built-in g_font.
     */
    g_skin = new Skin(g_env->getSkin());
    g_env->setSkin(g_skin);
    //g_skin = g_env->getSkin();
    
    // font size is resolution-dependent.
    // normal text will range from 0.8, in 640x* resolutions (won't scale below that) to
    // 1.0, in 1024x* resolutions, and linearly up
    // normal text will range from 0.2, in 640x* resolutions (won't scale below that) to
    // 0.4, in 1024x* resolutions, and linearly up
    const int screen_width = irr_driver->getFrameSize().Width;
    const float normal_text_scale = 0.7f + 0.2f*std::max(0, screen_width - 640)/564.0f;
    const float title_text_scale = 0.2f + 0.2f*std::max(0, screen_width - 640)/564.0f;

    //ScalableFont* sfont = new ScalableFont(g_env, (file_manager->getGUIDir() + "/okolaks.xml").c_str());
    ScalableFont* sfont = new ScalableFont(g_env, file_manager->getFontFile("StkFont.xml").c_str() );
    sfont->setScale(normal_text_scale);
    sfont->setKerningHeight(-5);
    g_font = sfont;
    
    Private::font_height = g_font->getDimension( L"X" ).Height;

    //ScalableFont* sfont_smaller = new ScalableFont(g_env, file_manager->getFontFile("StkFont.xml").c_str() );
    ScalableFont* sfont_smaller = sfont->getHollowCopy();
    sfont_smaller->setScale(normal_text_scale*0.8f);
    sfont_smaller->setKerningHeight(-5);
    g_small_font = sfont_smaller;
    
    Private::small_font_height = g_small_font->getDimension( L"X" ).Height;

    ScalableFont* sfont2 = new ScalableFont(g_env, file_manager->getFontFile("title_font.xml").c_str() );
    sfont2->m_fallback_font = sfont;
    sfont2->m_fallback_font_scale = 4.0f; // because the fallback font is much smaller than the title font
    sfont2->m_fallback_kerning_width = 15;
    sfont2->setScale(title_text_scale);
    sfont2->setKerningWidth(-18);
    sfont2->m_black_border = true;
    g_title_font = sfont2;
    

    if (g_font != NULL) g_skin->setFont(g_font);
    
    //g_skin->setFont(g_env->getBuiltInFont(), EGDF_TOOLTIP);
    
    // set event receiver
    g_device->setEventReceiver(EventHandler::get());
}

// -----------------------------------------------------------------------------
    
void render(float elapsed_time)
{    
    GUIEngine::dt = elapsed_time;
    
     // ---- menu drawing
    
    // draw background image and sections
    
    const GameState gamestate = g_state_manager->getGameState();
    
    if (gamestate == MENU && !GUIEngine::getCurrentScreen()->needs3D())
    {
        g_skin->drawBgImage();
    }
    else if (gamestate == INGAME_MENU)
    {
        g_skin->drawBGFadeColor();
    }
    
#if (IRRLICHT_VERSION_MAJOR == 1) && (IRRLICHT_VERSION_MINOR >= 7)
    g_driver->enableMaterial2D();
#endif
    
    if (gamestate == MENU || gamestate == INGAME_MENU)
    {
        g_skin->renderSections();
    }
    
    // let irrLicht do the rest (the Skin object will be called for further render)
    g_env->drawAll();
    
    // ---- some menus may need updating
    if (gamestate != GAME)
    {
        if (ModalDialog::isADialogActive()) ModalDialog::getCurrent()->onUpdate(dt);
        else                                getCurrentScreen()->onUpdate(elapsed_time, g_driver);
    }
    else
    {
        if (ModalDialog::isADialogActive()) ModalDialog::getCurrent()->onUpdate(dt);
        else                                World::getWorld()->getRaceGUI()->renderGlobal(elapsed_time);
    }
    
    if (gamestate != GAME && !gui_messages.empty())
    {
        core::dimension2d<u32> screen_size = irr_driver->getFrameSize();
        const int text_height = getFontHeight() + 20;
        const int y_from = screen_size.Height - text_height;
        
        int count = 0;
        
        std::vector<MenuMessage>::iterator it;
        for (it=gui_messages.begin(); it != gui_messages.end();)
        {
            if ((*it).m_time > 0.0f)
            {
                (*it).m_time -= dt;
                
                
                Private::g_font->draw((*it).m_message.c_str(),
                                      core::rect<s32>( core::position2d<s32>(0, y_from - count*text_height),
                                                      core::dimension2d<s32>(screen_size.Width, text_height) ),
                                      video::SColor(255, 255, 0, 0),
                                      true /* hcenter */, true /* vcenter */);  
                count++;
                it++;
            }
            else
            {
                it = gui_messages.erase(it);
            }
        }
    }
    
#if (IRRLICHT_VERSION_MAJOR == 1) && (IRRLICHT_VERSION_MINOR >= 7)
    g_driver->enableMaterial2D(false);
#endif
}   // render

// -----------------------------------------------------------------------------    

void renderLoading()
{
    g_skin->drawBgImage();
    ITexture* loading = irr_driver->getTexture( file_manager->getGUIDir() + "/loading.png" );
    
    const int texture_w = loading->getSize().Width;
    const int texture_h = loading->getSize().Height;
    
    core::dimension2d<u32> frame_size = GUIEngine::getDriver()->getCurrentRenderTargetSize();
    const int screen_w = frame_size.Width;
    const int screen_h = frame_size.Height;
    
    const core::rect< s32 > dest_area = core::rect< s32 >(screen_w/2 - texture_w/2,
                                                          screen_h/2 - texture_h/2,
                                                          screen_w/2 + texture_w/2,
                                                          screen_h/2 + texture_h/2);
    
    const core::rect< s32 > source_area = core::rect< s32 >(0, 0, texture_w, texture_h);
    
    GUIEngine::getDriver()->draw2DImage( loading, dest_area, source_area,
                                        0 /* no clipping */, 0, true /* alpha */);
    
    
    g_title_font->draw(_("Loading"),
                       core::rect< s32 >( 0, screen_h/2 + texture_h/2, screen_w, screen_h ),
                       SColor(255,255,255,255),
                       true/* center h */, false /* center v */ );
    
} // renderLoading
    
// -----------------------------------------------------------------------------    
Widget* getWidget(const char* name)
{
    // if a modal dialog is shown, search within it too
    if (ModalDialog::isADialogActive())
    {
        Widget* widgetWithinDialog = Screen::getWidget(name, &(ModalDialog::getCurrent()->m_children));
        if (widgetWithinDialog != NULL) return widgetWithinDialog;
    }
    
    Screen* screen = getCurrentScreen();
    
    if (screen == NULL) return NULL;
    
    return Screen::getWidget(name,  &screen->m_widgets);
}
// -----------------------------------------------------------------------------    
Widget* getWidget(const int id)
{
    // if a modal dialog is shown, search within it too
    if (ModalDialog::isADialogActive())
    {        
        Widget* widgetWithinDialog = Screen::getWidget(id, &(ModalDialog::getCurrent()->m_children));
        if (widgetWithinDialog != NULL) return widgetWithinDialog;
    }
    
    Screen* screen = getCurrentScreen();
    
    if (screen == NULL) return NULL;
    
    return Screen::getWidget(id,  &screen->m_widgets);
}

        
}
