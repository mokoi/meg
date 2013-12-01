#define GUIPATCH_DIALOG "<?xml version=\"1.0\"?>\n<interface>\n\t<!-- interface-requires gtk+ 2.12 -->\n\t<!-- interface-naming-policy project-wide -->\n\t<object class=\"GtkWindow\" id=\"window1\">\n\t\t<property name=\"width_request\">400</property>\n\t\t<property name=\"height_request\">300</property>\n\t\t<property name=\"title\" translatable=\"yes\">Compiling Game Patch</property>\n\t\t<child>\n\t\t\t<object class=\"GtkVBox\" id=\"vbox1\">\n\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t<property name=\"orientation\">vertical</property>\n\t\t\t\t<child>\n\t\t\t\t\t<object class=\"GtkEventBox\" id=\"alchera-title\">\n\t\t\t\t\t\t<property name=\"name\">alchera-title</property>\n\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t<object class=\"GtkHBox\" id=\"hbox1\">\n\t\t\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t\t\t<object class=\"GtkImage\" id=\"image1\">\n\t\t\t\t\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"stock\">gtk-execute</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"icon-size\">5</property>\n\t\t\t\t\t\t\t\t\t</object>\n\t\t\t\t\t\t\t\t\t<packing>\n\t\t\t\t\t\t\t\t\t\t<property name=\"expand\">False</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"padding\">2</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"position\">0</property>\n\t\t\t\t\t\t\t\t\t</packing>\n\t\t\t\t\t\t\t\t</child>\n\t\t\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t\t\t<object class=\"GtkLabel\" id=\"alchera-label\">\n\t\t\t\t\t\t\t\t\t\t<property name=\"name\">alchera-label</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"xalign\">0</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"label\" translatable=\"yes\">&lt;b&gt;Compiling Game Patch&lt;/b&gt;</property>\n\t\t\t\t\t\t\t\t\t\t<property name=\"use_markup\">True</property>\n\t\t\t\t\t\t\t\t\t</object>\n\t\t\t\t\t\t\t\t\t<packing>\n\t\t\t\t\t\t\t\t\t\t<property name=\"position\">1</property>\n\t\t\t\t\t\t\t\t\t</packing>\n\t\t\t\t\t\t\t\t</child>\n\t\t\t\t\t\t\t</object>\n\t\t\t\t\t\t</child>\n\t\t\t\t\t</object>\n\t\t\t\t\t<packing>\n\t\t\t\t\t\t<property name=\"expand\">False</property>\n\t\t\t\t\t\t<property name=\"fill\">False</property>\n\t\t\t\t\t\t<property name=\"position\">0</property>\n\t\t\t\t\t</packing>\n\t\t\t\t</child>\n\t\t\t\t<child>\n\t\t\t\t\t<object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\">\n\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t<property name=\"can_focus\">True</property>\n\t\t\t\t\t\t<property name=\"hscrollbar_policy\">automatic</property>\n\t\t\t\t\t\t<property name=\"vscrollbar_policy\">automatic</property>\n\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t<object class=\"GtkTextView\" id=\"textview1\">\n\t\t\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t\t\t<property name=\"can_focus\">True</property>\n\t\t\t\t\t\t\t</object>\n\t\t\t\t\t\t</child>\n\t\t\t\t\t</object>\n\t\t\t\t\t<packing>\n\t\t\t\t\t\t<property name=\"position\">1</property>\n\t\t\t\t\t</packing>\n\t\t\t\t</child>\n\t\t\t\t<child>\n\t\t\t\t\t<object class=\"GtkStatusbar\" id=\"statusbar1\">\n\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t<property name=\"spacing\">2</property>\n\t\t\t\t\t\t<property name=\"has_resize_grip\">False</property>\n\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t<object class=\"GtkProgressBar\" id=\"progressbar1\">\n\t\t\t\t\t\t\t\t<property name=\"visible\">True</property>\n\t\t\t\t\t\t\t\t<property name=\"activity_mode\">True</property>\n\t\t\t\t\t\t\t\t<property name=\"show_text\">True</property>\n\t\t\t\t\t\t\t\t<property name=\"text\" translatable=\"yes\">Compiling</property>\n\t\t\t\t\t\t\t</object>\n\t\t\t\t\t\t\t<packing>\n\t\t\t\t\t\t\t\t<property name=\"position\">0</property>\n\t\t\t\t\t\t\t</packing>\n\t\t\t\t\t\t</child>\n\t\t\t\t\t\t<child>\n\t\t\t\t\t\t\t<placeholder/>\n\t\t\t\t\t\t</child>\n\t\t\t\t\t</object>\n\t\t\t\t\t<packing>\n\t\t\t\t\t\t<property name=\"expand\">False</property>\n\t\t\t\t\t\t<property name=\"position\">2</property>\n\t\t\t\t\t</packing>\n\t\t\t\t</child>\n\t\t\t</object>\n\t\t</child>\n\t</object>\n</interface>\n";
