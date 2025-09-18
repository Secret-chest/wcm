#pragma once

#include <gtkmm.h>
#include <string>
#include <wayfire/config/section.hpp>

using wf_section = std::shared_ptr<wf::config::section_t>;

/*!
 * Simple fuzzy-search. Finds `pattern` in `text`. Always returns `true` when
 * `pattern` is empty.
 */
bool find_string(std::string text, std::string pattern);

bool begins_with(const std::string & str, const std::string & prefix);

std::map<std::string, std::string> get_xkb_layouts(const std::string& ruleset);
std::map<std::string, std::string> get_xkb_models(const std::string& ruleset);

/*!
 * Button with text and icon.
 */
class PrettyButton : public Gtk::Button
{
  public:
    PrettyButton(const Glib::ustring & text, const Glib::ustring & icon,
        Gtk::IconSize icon_size = Gtk::IconSize::LARGE) :
        label(text)
    {
        image.set_from_icon_name(icon);
        image.set_icon_size(icon_size);
        layout.append(image);
        layout.append(label);
        layout.set_halign(Gtk::Align::CENTER);
        set_child(layout);
    }

  private:
    Gtk::Box layout = Gtk::Box(Gtk::Orientation::HORIZONTAL, 5);
    Gtk::Image image;
    Gtk::Label label;
};
