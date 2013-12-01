#define GUIPATCH_PAGE "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy project-wide -->\n  <object class=\"GtkListStore\" id=\"store_files\">\n    <columns>\n      <!-- column-name checkbox -->\n      <column type=\"gboolean\"/>\n      <!-- column-name filename -->\n      <column type=\"gchararray\"/>\n    </columns>\n  </object>\n  <object class=\"GtkDialog\" id=\"dialog\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"border_width\">5</property>\n    <property name=\"title\" translatable=\"yes\">Create Patch file</property>\n    <property name=\"modal\">True</property>\n    <property name=\"window_position\">center-on-parent</property>\n    <property name=\"type_hint\">dialog</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox1\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <child>\n          <object class=\"GtkLabel\" id=\"alchera-label\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"xalign\">0</property>\n            <property name=\"label\" translatable=\"yes\">&lt;b&gt;Patch&lt;/b&gt;\nCreate patch for previous releases</property>\n            <property name=\"use_markup\">True</property>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkHBox\" id=\"hbox2\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkLabel\" id=\"label2\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"xalign\">0</property>\n                <property name=\"label\" translatable=\"yes\">Select Previous Version</property>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkFileChooserButton\" id=\"file_previousgame\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">1</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkFrame\" id=\"frame1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"label_xalign\">0</property>\n            <child>\n              <object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"hscrollbar_policy\">automatic</property>\n                <property name=\"vscrollbar_policy\">automatic</property>\n                <child>\n                  <object class=\"GtkTreeView\" id=\"treeview1\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"model\">store_files</property>\n                    <property name=\"headers_clickable\">False</property>\n                    <property name=\"search_column\">0</property>\n                    <property name=\"enable_grid_lines\">vertical</property>\n                    <child>\n                      <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n                        <property name=\"sizing\">autosize</property>\n                        <property name=\"title\">Include</property>\n                        <property name=\"clickable\">True</property>\n                        <child>\n                          <object class=\"GtkCellRendererToggle\" id=\"cellrenderertoggle1\">\n                            <signal name=\"toggled\" handler=\"Patch_CheckInclude\" object=\"liststore1\" swapped=\"yes\"/>\n                          </object>\n                          <attributes>\n                            <attribute name=\"active\">0</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                    </child>\n                    <child>\n                      <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn2\">\n                        <property name=\"sizing\">autosize</property>\n                        <property name=\"title\">Filename</property>\n                        <property name=\"reorderable\">True</property>\n                        <child>\n                          <object class=\"GtkCellRendererText\" id=\"cellrenderertext1\"/>\n                          <attributes>\n                            <attribute name=\"text\">1</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                    </child>\n                  </object>\n                </child>\n              </object>\n            </child>\n            <child type=\"label\">\n              <object class=\"GtkLabel\" id=\"label1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">&lt;b&gt;Changed Files&lt;/b&gt;</property>\n                <property name=\"use_markup\">True</property>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button2\">\n                <property name=\"label\">gtk-ok</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button4\">\n                <property name=\"label\">gtk-cancel</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">3</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"-5\">button2</action-widget>\n      <action-widget response=\"0\">button4</action-widget>\n    </action-widgets>\n  </object>\n</interface>\n";
