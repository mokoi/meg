#define GUIMAP_ADVANCE "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkAction\" id=\"action1\">\n    <property name=\"label\" translatable=\"yes\">Map Script</property>\n    <property name=\"tooltip\" translatable=\"yes\">Edit the script for the current map</property>\n    <property name=\"stock_id\">gtk-edit</property>\n    <property name=\"always_show_image\">True</property>\n  </object>\n  <object class=\"GtkAction\" id=\"action2\">\n    <property name=\"label\" translatable=\"yes\">Add</property>\n    <property name=\"short_label\" translatable=\"yes\">Add</property>\n    <property name=\"tooltip\" translatable=\"yes\">Add a new option</property>\n    <property name=\"stock_id\">gtk-add</property>\n  </object>\n  <object class=\"GtkAdjustment\" id=\"adjust_map_height\">\n    <property name=\"lower\">1</property>\n    <property name=\"upper\">64</property>\n    <property name=\"value\">1</property>\n    <property name=\"step_increment\">1</property>\n    <property name=\"page_increment\">10</property>\n  </object>\n  <object class=\"GtkAdjustment\" id=\"adjust_map_width\">\n    <property name=\"lower\">1</property>\n    <property name=\"upper\">64</property>\n    <property name=\"value\">1</property>\n    <property name=\"step_increment\">1</property>\n    <property name=\"page_increment\">10</property>\n  </object>\n  <object class=\"GtkDialog\" id=\"dialog\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"title\" translatable=\"yes\">Map Options</property>\n    <property name=\"modal\">True</property>\n    <property name=\"window_position\">center-on-parent</property>\n    <property name=\"default_height\">400</property>\n    <property name=\"destroy_with_parent\">True</property>\n    <property name=\"type_hint\">normal</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox\">\n        <property name=\"can_focus\">False</property>\n        <property name=\"spacing\">2</property>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area\">\n            <property name=\"can_focus\">False</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button-apply\">\n                <property name=\"label\">gtk-apply</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button-cancel\">\n                <property name=\"label\">gtk-cancel</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button-edit\">\n                <property name=\"related_action\">action1</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">2</property>\n                <property name=\"secondary\">True</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkEventBox\" id=\"alchera-title\">\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkHBox\" id=\"hbox3\">\n                <property name=\"can_focus\">False</property>\n                <child>\n                  <object class=\"GtkImage\" id=\"image7\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"stock\">gtk-about</property>\n                    <property name=\"icon-size\">3</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">False</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"padding\">2</property>\n                    <property name=\"position\">0</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"alchera-label\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"xalign\">0</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Map Advance Setting&lt;/b&gt;\nUnknown Map</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">True</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">1</property>\n                  </packing>\n                </child>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">1</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkNotebook\" id=\"notebook1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">True</property>\n            <child>\n              <object class=\"GtkTable\" id=\"table4\">\n                <property name=\"can_focus\">False</property>\n                <property name=\"n_rows\">6</property>\n                <property name=\"n_columns\">2</property>\n                <child>\n                  <object class=\"GtkSpinButton\" id=\"spin_w\">\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"invisible_char\">\342\227\217</property>\n                    <property name=\"primary_icon_activatable\">False</property>\n                    <property name=\"secondary_icon_activatable\">False</property>\n                    <property name=\"primary_icon_sensitive\">True</property>\n                    <property name=\"secondary_icon_sensitive\">True</property>\n                    <property name=\"adjustment\">adjust_map_width</property>\n                    <property name=\"numeric\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"left_attach\">1</property>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"label15\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Width:&lt;/b&gt;</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"label16\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Height:&lt;/b&gt;</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"top_attach\">1</property>\n                    <property name=\"bottom_attach\">2</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkSpinButton\" id=\"spin_h\">\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"invisible_char\">\342\227\217</property>\n                    <property name=\"primary_icon_activatable\">False</property>\n                    <property name=\"secondary_icon_activatable\">False</property>\n                    <property name=\"primary_icon_sensitive\">True</property>\n                    <property name=\"secondary_icon_sensitive\">True</property>\n                    <property name=\"adjustment\">adjust_map_height</property>\n                    <property name=\"numeric\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"left_attach\">1</property>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"top_attach\">1</property>\n                    <property name=\"bottom_attach\">2</property>\n                    <property name=\"x_options\">GTK_FILL</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"label3\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"label\" translatable=\"yes\">Wrap:</property>\n                    <attributes>\n                      <attribute name=\"weight\" value=\"bold\"/>\n                    </attributes>\n                  </object>\n                  <packing>\n                    <property name=\"top_attach\">2</property>\n                    <property name=\"bottom_attach\">3</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkComboBox\" id=\"combo_wrapmode\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"model\">wrap_store</property>\n                    <property name=\"active\">0</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext1\"/>\n                      <attributes>\n                        <attribute name=\"text\">0</attribute>\n                      </attributes>\n                    </child>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext2\">\n                        <property name=\"text\">-</property>\n                      </object>\n                    </child>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext3\"/>\n                      <attributes>\n                        <attribute name=\"text\">1</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                  <packing>\n                    <property name=\"left_attach\">1</property>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"top_attach\">2</property>\n                    <property name=\"bottom_attach\">3</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkCheckButton\" id=\"check_centerview\">\n                    <property name=\"label\" translatable=\"yes\">Center Camera</property>\n                    <property name=\"use_action_appearance\">False</property>\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"receives_default\">False</property>\n                    <property name=\"draw_indicator\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"top_attach\">3</property>\n                    <property name=\"bottom_attach\">4</property>\n                    <property name=\"x_options\">GTK_FILL</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkCheckButton\" id=\"check_independent\">\n                    <property name=\"label\" translatable=\"yes\">Independent</property>\n                    <property name=\"use_action_appearance\">False</property>\n                    <property name=\"visible\">True</property>\n                    <property name=\"sensitive\">False</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"receives_default\">False</property>\n                    <property name=\"draw_indicator\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"top_attach\">4</property>\n                    <property name=\"bottom_attach\">5</property>\n                    <property name=\"x_options\">GTK_FILL</property>\n                    <property name=\"y_options\">GTK_FILL</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkColorButton\" id=\"button_colour\">\n                    <property name=\"use_action_appearance\">False</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"receives_default\">True</property>\n                    <property name=\"color\">#000000000000</property>\n                  </object>\n                  <packing>\n                    <property name=\"left_attach\">1</property>\n                    <property name=\"right_attach\">2</property>\n                    <property name=\"top_attach\">5</property>\n                    <property name=\"bottom_attach\">6</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"label5\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Background Colour:&lt;/b&gt;</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"top_attach\">5</property>\n                    <property name=\"bottom_attach\">6</property>\n                  </packing>\n                </child>\n              </object>\n              <packing>\n                <property name=\"tab_expand\">True</property>\n                <property name=\"tab_fill\">False</property>\n              </packing>\n            </child>\n            <child type=\"tab\">\n              <object class=\"GtkLabel\" id=\"label1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">Settings</property>\n              </object>\n              <packing>\n                <property name=\"tab_fill\">False</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkVBox\" id=\"runtime_page\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <child>\n                  <object class=\"GtkToolbar\" id=\"toolbar1\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"toolbar_style\">both-horiz</property>\n                    <property name=\"show_arrow\">False</property>\n                    <child>\n                      <object class=\"GtkToolButton\" id=\"button_addoption\">\n                        <property name=\"related_action\">action2</property>\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">False</property>\n                        <property name=\"label\" translatable=\"yes\">toolbutton1</property>\n                        <property name=\"use_underline\">True</property>\n                      </object>\n                      <packing>\n                        <property name=\"expand\">False</property>\n                        <property name=\"homogeneous\">True</property>\n                      </packing>\n                    </child>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">False</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">0</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"hscrollbar_policy\">never</property>\n                    <property name=\"vscrollbar_policy\">automatic</property>\n                    <child>\n                      <object class=\"GtkViewport\" id=\"viewport1\">\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">False</property>\n                        <property name=\"resize_mode\">queue</property>\n                        <child>\n                          <object class=\"GtkTable\" id=\"box_runtime\">\n                            <property name=\"visible\">True</property>\n                            <property name=\"can_focus\">False</property>\n                            <property name=\"n_columns\">3</property>\n                            <child>\n                              <placeholder/>\n                            </child>\n                            <child>\n                              <placeholder/>\n                            </child>\n                            <child>\n                              <placeholder/>\n                            </child>\n                          </object>\n                        </child>\n                      </object>\n                    </child>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">True</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">1</property>\n                  </packing>\n                </child>\n              </object>\n              <packing>\n                <property name=\"position\">1</property>\n                <property name=\"tab_expand\">True</property>\n              </packing>\n            </child>\n            <child type=\"tab\">\n              <object class=\"GtkLabel\" id=\"label2\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">Runtime Settings</property>\n              </object>\n              <packing>\n                <property name=\"position\">1</property>\n                <property name=\"tab_fill\">False</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkTable\" id=\"box_graphics\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"n_columns\">2</property>\n                <child>\n                  <placeholder/>\n                </child>\n                <child>\n                  <placeholder/>\n                </child>\n              </object>\n              <packing>\n                <property name=\"position\">2</property>\n              </packing>\n            </child>\n            <child type=\"tab\">\n              <object class=\"GtkLabel\" id=\"label4\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">Graphics</property>\n              </object>\n              <packing>\n                <property name=\"position\">2</property>\n                <property name=\"tab_fill\">False</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"-10\">button-apply</action-widget>\n      <action-widget response=\"0\">button-cancel</action-widget>\n      <action-widget response=\"1\">button-edit</action-widget>\n    </action-widgets>\n  </object>\n  <object class=\"GtkListStore\" id=\"wrap_store\">\n    <columns>\n      <!-- column-name name -->\n      <column type=\"gchararray\"/>\n      <!-- column-name value -->\n      <column type=\"gint\"/>\n    </columns>\n    <data>\n      <row>\n        <col id=\"0\" translatable=\"yes\">None</col>\n        <col id=\"1\">0</col>\n      </row>\n      <row>\n        <col id=\"0\" translatable=\"yes\">Left and right</col>\n        <col id=\"1\">1</col>\n      </row>\n      <row>\n        <col id=\"0\" translatable=\"yes\">Top and bottom</col>\n        <col id=\"1\">2</col>\n      </row>\n      <row>\n        <col id=\"0\" translatable=\"yes\">Both</col>\n        <col id=\"1\">3</col>\n      </row>\n    </data>\n  </object>\n</interface>\n";
