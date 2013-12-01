#define GUIABOUT_WINDOW_CUSTOM "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <!-- interface-requires gtk+ 2.12 -->\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkAboutDialog\" id=\"alchera_about_dialog\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n    <property name=\"border_width\">5</property>\n    <property name=\"title\" translatable=\"yes\">About Quest Designer</property>\n    <property name=\"modal\">True</property>\n    <property name=\"window_position\">center-on-parent</property>\n    <property name=\"destroy_with_parent\">True</property>\n    <property name=\"type_hint\">dialog</property>\n    <property name=\"program_name\">Quest Designer</property>\n    <property name=\"version\">2.0 Alpha</property>\n    <property name=\"copyright\" translatable=\"yes\">Copyright \302\251 2007-2013 Luke Salisbury\n</property>\n    <property name=\"comments\" translatable=\"yes\">Powered by Mokoi Gaming's Meg</property>\n    <property name=\"website\">http://openzelda.net/</property>\n    <property name=\"website_label\" translatable=\"yes\">openzelda.net</property>\n    <property name=\"license\" translatable=\"yes\">This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.\n\n\nPermission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:\n\n1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.\n2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.\n3. This notice may not be removed or altered from any source distribution.</property>\n    <property name=\"authors\">Luke Salisbury</property>\n    <property name=\"documenters\"></property>\n    <property name=\"artists\">Luke Salisbury, Tango Project</property>\n    <property name=\"logo_icon_name\">openzelda-quest-designer</property>\n\t<property name=\"wrap_license\">True</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox1\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n        <property name=\"spacing\">2</property>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n            <property name=\"layout_style\">end</property>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <placeholder/>\n        </child>\n      </object>\n    </child>\n  </object>\n</interface>\n";
