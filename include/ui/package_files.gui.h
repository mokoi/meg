#define GUIPACKAGE_FILES "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkListStore\" id=\"store_files\">\n    <columns>\n      <!-- column-name enable -->\n      <column type=\"gboolean\"/>\n      <!-- column-name gchararray -->\n      <column type=\"gchararray\"/>\n      <!-- column-name storedinfo -->\n      <column type=\"gpointer\"/>\n    </columns>\n  </object>\n  <object class=\"GtkMessageDialog\" id=\"messagedialog1\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"border_width\">5</property>\n    <property name=\"type_hint\">dialog</property>\n    <property name=\"skip_taskbar_hint\">True</property>\n    <property name=\"text\" translatable=\"yes\">Install Package</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox2\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <property name=\"spacing\">2</property>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area2\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button1\">\n                <property name=\"label\">gtk-ok</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button2\">\n                <property name=\"label\">gtk-cancel</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkExpander\" id=\"expander1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">True</property>\n            <child>\n              <object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"hscrollbar_policy\">automatic</property>\n                <property name=\"vscrollbar_policy\">automatic</property>\n                <child>\n                  <object class=\"GtkTreeView\" id=\"treeview1\">\n                    <property name=\"height_request\">300</property>\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"model\">store_files</property>\n                    <property name=\"headers_visible\">False</property>\n                    <property name=\"headers_clickable\">False</property>\n                    <child>\n                      <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n                        <child>\n                          <object class=\"GtkCellRendererToggle\" id=\"cellrenderertoggle1\"/>\n                          <attributes>\n                            <attribute name=\"active\">0</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                    </child>\n                    <child>\n                      <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn2\">\n                        <property name=\"title\" translatable=\"yes\">column</property>\n                        <child>\n                          <object class=\"GtkCellRendererText\" id=\"cellrenderertext1\"/>\n                          <attributes>\n                            <attribute name=\"text\">1</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                    </child>\n                  </object>\n                </child>\n              </object>\n            </child>\n            <child type=\"label\">\n              <object class=\"GtkLabel\" id=\"label1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">Details</property>\n                <attributes>\n                  <attribute name=\"weight\" value=\"bold\"/>\n                </attributes>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"-1\">button1</action-widget>\n      <action-widget response=\"-5\">button2</action-widget>\n    </action-widgets>\n  </object>\n</interface>\n";
