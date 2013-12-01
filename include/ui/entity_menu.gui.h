#define GUIENTITY_MENU "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkAction\" id=\"menu_compile\">\n    <property name=\"label\">Compile</property>\n  </object>\n  <object class=\"GtkAction\" id=\"menu_open\">\n    <property name=\"label\">Open</property>\n    <property name=\"icon_name\">GTK_STOCK_OPEN</property>\n  </object>\n  <object class=\"GtkAction\" id=\"menu_remove\">\n    <property name=\"label\">Remove</property>\n    <property name=\"icon_name\">GTK_STOCK_DELETE</property>\n  </object>\n  <object class=\"GtkAction\" id=\"menu_settings\">\n    <property name=\"label\">Runtime Settings</property>\n  </object>\n  <object class=\"GtkMenu\" id=\"object_menu\">\n    <property name=\"can_focus\">False</property>\n    <child>\n      <object class=\"GtkMenuItem\" id=\"menuitem1\">\n        <property name=\"related_action\">menu_open</property>\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n      </object>\n    </child>\n    <child>\n      <object class=\"GtkMenuItem\" id=\"menuitem2\">\n        <property name=\"related_action\">menu_compile</property>\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n      </object>\n    </child>\n    <child>\n      <object class=\"GtkMenuItem\" id=\"menuitem3\">\n        <property name=\"related_action\">menu_settings</property>\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n      </object>\n    </child>\n    <child>\n      <object class=\"GtkSeparatorMenuItem\" id=\"menuitem4\">\n        <property name=\"use_action_appearance\">False</property>\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n      </object>\n    </child>\n    <child>\n      <object class=\"GtkMenuItem\" id=\"menuitem5\">\n        <property name=\"related_action\">menu_remove</property>\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n      </object>\n    </child>\n  </object>\n</interface>\n";