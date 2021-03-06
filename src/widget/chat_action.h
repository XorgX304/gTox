/**
    gTox a GTK-based tox-client - https://github.com/KoKuToru/gTox.git

    Copyright (C) 2015  Luca Béla Palkovics

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
**/
#ifndef WIDGETCHATACTIONREAL_H
#define WIDGETCHATACTIONREAL_H

#include <gtkmm.h>
#include "label.h"
#include "utils/debug.h"
#include "utils/dispatcher.h"

namespace widget {
    class chat_action : public Gtk::Revealer, public utils::debug::track_obj<chat_action> {
        private:
            class label: public widget::label {
                private:
                    Glib::PropertyProxy_ReadOnly<Glib::ustring> m_name;
                    Glib::DateTime m_time;
                public:
                    label(Glib::PropertyProxy_ReadOnly<Glib::ustring> name,
                          Glib::DateTime time,
                          const Glib::ustring& message);
                    virtual Glib::ustring get_selection() override;
                    virtual ~label() {}
            };

            Gtk::HBox  m_hbox;
            Gtk::Label m_username;
            label m_label;
            utils::dispatcher m_dispatcher;

            Glib::RefPtr<Glib::Binding> m_username_binding;

        public:
            chat_action(Glib::PropertyProxy_ReadOnly<Glib::ustring> name,
                        Glib::DateTime time,
                        const Glib::ustring& text);
            virtual ~chat_action();
    };
}
#endif
