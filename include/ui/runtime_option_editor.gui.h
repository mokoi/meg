#define GUIRUNTIME_OPTION_EDITOR "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkDialog\" id=\"dialog\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"title\" translatable=\"yes\">Entity Runtime Settings</property>\n    <property name=\"window_position\">center-on-parent</property>\n    <property name=\"destroy_with_parent\">True</property>\n    <property name=\"type_hint\">dialog</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox3\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n        <property name=\"spacing\">2</property>\n        <child>\n          <object class=\"GtkEventBox\" id=\"alchera-title\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n            <child>\n              <object class=\"GtkHBox\" id=\"hbox2\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                <child>\n                  <object class=\"GtkImage\" id=\"image2\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                    <property name=\"xpad\">4</property>\n                    <property name=\"ypad\">4</property>\n                    <property name=\"stock\">gtk-about</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">False</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"padding\">2</property>\n                    <property name=\"position\">0</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"alchera-label\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                    <property name=\"xalign\">0</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Runtime Settings&lt;/b&gt;\nUnknown Entity</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">True</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">1</property>\n                  </packing>\n                </child>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkScrolledWindow\" id=\"scrolledwindow3\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">True</property>\n            <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n            <property name=\"hscrollbar_policy\">automatic</property>\n            <property name=\"vscrollbar_policy\">automatic</property>\n            <child>\n              <object class=\"GtkTreeView\" id=\"tree_items\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                <property name=\"model\">store_items</property>\n                <property name=\"enable_search\">False</property>\n                <property name=\"enable_grid_lines\">both</property>\n                <property name=\"tooltip_column\">2</property>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n                    <property name=\"title\">Name</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext1\"/>\n                      <attributes>\n                        <attribute name=\"text\">0</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn2\">\n                    <property name=\"resizable\">True</property>\n                    <property name=\"title\">Default Value</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cell_value\">\n                        <property name=\"editable\">True</property>\n                      </object>\n                      <attributes>\n                        <attribute name=\"text\">1</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn3\">\n                    <property name=\"resizable\">True</property>\n                    <property name=\"title\">Type</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cell_type\">\n                        <property name=\"editable\">True</property>\n                      </object>\n                      <attributes>\n                        <attribute name=\"text\">2</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">1</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkExpander\" id=\"expander1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">True</property>\n            <child>\n              <object class=\"GtkLabel\" id=\"label2\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"xalign\">0</property>\n                <property name=\"yalign\">0</property>\n                <property name=\"label\" translatable=\"yes\">\342\200\242 boolean\n\342\200\242 music\n\342\200\242 soundfx\n\342\200\242 hidden\n\342\200\242 entity\n\342\200\242 section\n\342\200\242 map\n\342\200\242 mapentity</property>\n              </object>\n            </child>\n            <child type=\"label\">\n              <object class=\"GtkLabel\" id=\"label1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">Available Types</property>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area3\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button3\">\n                <property name=\"label\">gtk-apply</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button5\">\n                <property name=\"label\">gtk-cancel</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"events\">GDK_POINTER_MOTION_MASK | GDK_POINTER_MOTION_HINT_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">3</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"-10\">button3</action-widget>\n      <action-widget response=\"0\">button5</action-widget>\n    </action-widgets>\n  </object>\n  <object class=\"GtkListStore\" id=\"store_items\">\n    <columns>\n      <!-- column-name name -->\n      <column type=\"gchararray\"/>\n      <!-- column-name value -->\n      <column type=\"gchararray\"/>\n      <!-- column-name type -->\n      <column type=\"gchararray\"/>\n    </columns>\n  </object>\n</interface>\n";