#define GUIVIRTUAL_SPRITE_DIALOG "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkListStore\" id=\"store_groups\">\n    <columns>\n      <!-- column-name gchararray1 -->\n      <column type=\"gchararray\"/>\n    </columns>\n    <data>\n      <row>\n        <col id=\"0\" translatable=\"yes\">No Map Loaded</col>\n      </row>\n    </data>\n  </object>\n  <object class=\"GtkImage\" id=\"image_next1\">\n    <property name=\"visible\">True</property>\n    <property name=\"can_focus\">False</property>\n    <property name=\"stock\">gtk-media-next</property>\n  </object>\n  <object class=\"GtkImage\" id=\"image_next2\">\n    <property name=\"visible\">True</property>\n    <property name=\"can_focus\">False</property>\n    <property name=\"stock\">gtk-media-next</property>\n  </object>\n  <object class=\"GtkImage\" id=\"image_prev1\">\n    <property name=\"visible\">True</property>\n    <property name=\"can_focus\">False</property>\n    <property name=\"stock\">gtk-media-previous</property>\n  </object>\n  <object class=\"GtkImage\" id=\"image_prev2\">\n    <property name=\"visible\">True</property>\n    <property name=\"can_focus\">False</property>\n    <property name=\"stock\">gtk-media-previous</property>\n  </object>\n  <object class=\"GtkListStore\" id=\"store_objects\">\n    <columns>\n      <!-- column-name icon -->\n      <column type=\"GdkPixbuf\"/>\n      <!-- column-name gchararray1 -->\n      <column type=\"gchararray\"/>\n      <!-- column-name gchararray2 -->\n      <column type=\"gchararray\"/>\n      <!-- column-name gboolean1 -->\n      <column type=\"gboolean\"/>\n      <!-- column-name guchar1 -->\n      <column type=\"guchar\"/>\n      <!-- column-name gint1 -->\n      <column type=\"gint\"/>\n      <!-- column-name gint2 -->\n      <column type=\"gint\"/>\n    </columns>\n  </object>\n  <object class=\"GtkListStore\" id=\"store_current_objects\">\n    <columns>\n      <!-- column-name guint1 -->\n      <column type=\"guint\"/>\n      <!-- column-name gchararray1 -->\n      <column type=\"gchararray\"/>\n      <!-- column-name gdouble1 -->\n      <column type=\"gdouble\"/>\n      <!-- column-name gdouble2 -->\n      <column type=\"gdouble\"/>\n      <!-- column-name guint2 -->\n      <column type=\"guint\"/>\n    </columns>\n    <data>\n      <row>\n        <col id=\"0\">0</col>\n        <col id=\"1\" translatable=\"yes\"></col>\n        <col id=\"2\">0</col>\n        <col id=\"3\">0</col>\n        <col id=\"4\">0</col>\n      </row>\n    </data>\n  </object>\n  <object class=\"GtkListStore\" id=\"store_sprites\">\n    <columns>\n      <!-- column-name sprite -->\n      <column type=\"gchararray\"/>\n      <!-- column-name x -->\n      <column type=\"glong\"/>\n      <!-- column-name y -->\n      <column type=\"glong\"/>\n      <!-- column-name flipmode -->\n      <column type=\"gint\"/>\n    </columns>\n  </object>\n  <object class=\"GtkDialog\" id=\"window\">\n    <property name=\"visible\">True</property>\n    <property name=\"can_focus\">False</property>\n    <property name=\"border_width\">5</property>\n    <property name=\"type_hint\">dialog</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox1\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <property name=\"spacing\">2</property>\n        <child>\n          <object class=\"GtkHBox\" id=\"hbox3\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkImage\" id=\"image1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"xpad\">4</property>\n                <property name=\"ypad\">4</property>\n                <property name=\"stock\">gtk-color-picker</property>\n                <property name=\"icon-size\">1</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkLabel\" id=\"label1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"xalign\">0</property>\n                <property name=\"label\" translatable=\"yes\">Virtual Sprite</property>\n                <attributes>\n                  <attribute name=\"weight\" value=\"bold\"/>\n                </attributes>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button_save\">\n                <property name=\"label\">gtk-save</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"button_close\">\n                <property name=\"label\">gtk-close</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkHBox\" id=\"hbox2\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkLabel\" id=\"label2\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"label\" translatable=\"yes\">&lt;b&gt;Name:&lt;/b&gt;</property>\n                <property name=\"use_markup\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">True</property>\n                <property name=\"padding\">2</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkLabel\" id=\"label_name\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"xalign\">0</property>\n                <property name=\"label\" translatable=\"yes\">label &lt;a href=\"\"&gt;rename&lt;/a&gt;</property>\n                <property name=\"use_markup\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkHBox\" id=\"hbox1\">\n            <property name=\"visible\">True</property>\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkTreeView\" id=\"treeview_objects\">\n                <property name=\"height_request\">200</property>\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"model\">store_current_objects</property>\n                <property name=\"headers_clickable\">False</property>\n                <property name=\"search_column\">0</property>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn2\">\n                    <property name=\"title\">ID</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext5\"/>\n                      <attributes>\n                        <attribute name=\"text\">1</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n                    <property name=\"title\">Type</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext4\"/>\n                      <attributes>\n                        <attribute name=\"text\">0</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn3\">\n                    <property name=\"title\">X</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext6\"/>\n                      <attributes>\n                        <attribute name=\"text\">2</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn4\">\n                    <property name=\"title\">Y</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext7\"/>\n                      <attributes>\n                        <attribute name=\"text\">3</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n                <child>\n                  <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn5\">\n                    <property name=\"title\">Z</property>\n                    <child>\n                      <object class=\"GtkCellRendererText\" id=\"cellrenderertext8\"/>\n                      <attributes>\n                        <attribute name=\"text\">4</attribute>\n                      </attributes>\n                    </child>\n                  </object>\n                </child>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkScrolledWindow\" id=\"scrolledwindow1\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">True</property>\n                <property name=\"hscrollbar_policy\">automatic</property>\n                <property name=\"vscrollbar_policy\">automatic</property>\n                <child>\n                  <object class=\"GtkViewport\" id=\"editor_viewport\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <child>\n                      <placeholder/>\n                    </child>\n                  </object>\n                </child>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkVBox\" id=\"vbox3\">\n                <property name=\"visible\">True</property>\n                <property name=\"can_focus\">False</property>\n                <child>\n                  <object class=\"GtkHBox\" id=\"hbox4\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">False</property>\n                    <child>\n                      <object class=\"GtkButton\" id=\"button_prevgroup\">\n                        <property name=\"use_action_appearance\">False</property>\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">True</property>\n                        <property name=\"receives_default\">True</property>\n                        <property name=\"image\">image_prev1</property>\n                      </object>\n                      <packing>\n                        <property name=\"expand\">False</property>\n                        <property name=\"fill\">False</property>\n                        <property name=\"position\">0</property>\n                      </packing>\n                    </child>\n                    <child>\n                      <object class=\"GtkComboBox\" id=\"combo_groups\">\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">False</property>\n                        <property name=\"model\">store_groups</property>\n                        <property name=\"active\">0</property>\n                        <child>\n                          <object class=\"GtkCellRendererText\" id=\"cellrenderertext3\"/>\n                          <attributes>\n                            <attribute name=\"text\">0</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                      <packing>\n                        <property name=\"expand\">True</property>\n                        <property name=\"fill\">True</property>\n                        <property name=\"position\">1</property>\n                      </packing>\n                    </child>\n                    <child>\n                      <object class=\"GtkButton\" id=\"button_nextgroup\">\n                        <property name=\"use_action_appearance\">False</property>\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">True</property>\n                        <property name=\"receives_default\">True</property>\n                        <property name=\"image\">image_next1</property>\n                        <property name=\"image_position\">right</property>\n                      </object>\n                      <packing>\n                        <property name=\"expand\">False</property>\n                        <property name=\"fill\">False</property>\n                        <property name=\"position\">2</property>\n                      </packing>\n                    </child>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">False</property>\n                    <property name=\"fill\">False</property>\n                    <property name=\"position\">0</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkScrolledWindow\" id=\"scrolledwindow3\">\n                    <property name=\"visible\">True</property>\n                    <property name=\"can_focus\">True</property>\n                    <property name=\"hscrollbar_policy\">automatic</property>\n                    <property name=\"vscrollbar_policy\">automatic</property>\n                    <property name=\"shadow_type\">in</property>\n                    <child>\n                      <object class=\"GtkIconView\" id=\"iconview_objects\">\n                        <property name=\"height_request\">128</property>\n                        <property name=\"visible\">True</property>\n                        <property name=\"can_focus\">True</property>\n                        <property name=\"receives_default\">True</property>\n                        <property name=\"events\">GDK_BUTTON_PRESS_MASK | GDK_KEY_PRESS_MASK | GDK_KEY_RELEASE_MASK | GDK_STRUCTURE_MASK</property>\n                        <property name=\"model\">store_objects</property>\n                        <property name=\"spacing\">2</property>\n                        <property name=\"row_spacing\">0</property>\n                        <property name=\"column_spacing\">0</property>\n                        <property name=\"tooltip_column\">1</property>\n                        <property name=\"item_padding\">4</property>\n                        <child>\n                          <object class=\"GtkCellRendererPixbuf\" id=\"cellrendererpixbuf1\"/>\n                          <attributes>\n                            <attribute name=\"pixbuf\">0</attribute>\n                          </attributes>\n                        </child>\n                        <child>\n                          <object class=\"GtkCellRendererText\" id=\"cellrenderertext9\"/>\n                          <attributes>\n                            <attribute name=\"text\">1</attribute>\n                          </attributes>\n                        </child>\n                      </object>\n                    </child>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">True</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">1</property>\n                  </packing>\n                </child>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">2</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">3</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"0\">button_save</action-widget>\n      <action-widget response=\"0\">button_close</action-widget>\n    </action-widgets>\n  </object>\n</interface>\n";
