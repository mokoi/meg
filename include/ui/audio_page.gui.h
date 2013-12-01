#define GUIAUDIO_PAGE "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkTreeStore\" id=\"meg_audio_store\">\n    <columns>\n      <!-- column-name displayname -->\n      <column type=\"gchararray\"/>\n      <!-- column-name type -->\n      <column type=\"gchararray\"/>\n      <!-- column-name preload -->\n      <column type=\"gint\"/>\n      <!-- column-name filename -->\n      <column type=\"gchararray\"/>\n      <!-- column-name image -->\n      <column type=\"gchararray\"/>\n    </columns>\n  </object>\n  <object class=\"GtkVBox\" id=\"meg_audio_widget\">\n    <property name=\"can_focus\">False</property>\n    <child>\n      <object class=\"GtkEventBox\" id=\"alchera-title\">\n        <property name=\"can_focus\">False</property>\n        <child>\n          <object class=\"GtkHBox\" id=\"hbox4\">\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkImage\" id=\"image2\">\n                <property name=\"can_focus\">False</property>\n                <property name=\"xpad\">2</property>\n                <property name=\"ypad\">2</property>\n                <property name=\"stock\">gtk-media-forward</property>\n                <property name=\"icon-size\">1</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkLabel\" id=\"alchera-label\">\n                <property name=\"can_focus\">False</property>\n                <property name=\"xalign\">0</property>\n                <property name=\"label\" translatable=\"yes\">&lt;b&gt;Audio Files&lt;/b&gt;</property>\n                <property name=\"use_markup\">True</property>\n                <property name=\"wrap_mode\">char</property>\n              </object>\n              <packing>\n                <property name=\"expand\">True</property>\n                <property name=\"fill\">True</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n        </child>\n      </object>\n      <packing>\n        <property name=\"expand\">False</property>\n        <property name=\"fill\">False</property>\n        <property name=\"position\">0</property>\n      </packing>\n    </child>\n    <child>\n      <object class=\"GtkScrolledWindow\" id=\"scrolledwindow3\">\n        <property name=\"can_focus\">True</property>\n        <property name=\"hscrollbar_policy\">automatic</property>\n        <property name=\"vscrollbar_policy\">automatic</property>\n        <child>\n          <object class=\"GtkTreeView\" id=\"meg_audio_main_treeview\">\n            <property name=\"can_focus\">True</property>\n            <property name=\"model\">meg_audio_store</property>\n            <property name=\"enable_search\">False</property>\n            <property name=\"show_expanders\">False</property>\n            <property name=\"enable_grid_lines\">both</property>\n            <child>\n              <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn1\">\n                <property name=\"sizing\">autosize</property>\n                <property name=\"title\">File</property>\n                <property name=\"expand\">True</property>\n                <child>\n                  <object class=\"GtkCellRendererText\" id=\"cell_type\"/>\n                  <attributes>\n                    <attribute name=\"text\">1</attribute>\n                  </attributes>\n                </child>\n                <child>\n                  <object class=\"GtkCellRendererText\" id=\"cell_name\"/>\n                  <attributes>\n                    <attribute name=\"text\">0</attribute>\n                  </attributes>\n                </child>\n              </object>\n            </child>\n            <child>\n              <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn3\">\n                <child>\n                  <object class=\"GtkCellRendererPixbuf\" id=\"cell_state\"/>\n                  <attributes>\n                    <attribute name=\"stock-id\">4</attribute>\n                  </attributes>\n                </child>\n              </object>\n            </child>\n            <child>\n              <object class=\"GtkTreeViewColumn\" id=\"treeviewcolumn2\">\n                <property name=\"sizing\">fixed</property>\n                <child>\n                  <object class=\"GtkCellRendererToggle\" id=\"cell_preload_toggle\"/>\n                  <attributes>\n                    <attribute name=\"active\">2</attribute>\n                  </attributes>\n                </child>\n              </object>\n            </child>\n          </object>\n        </child>\n      </object>\n      <packing>\n        <property name=\"expand\">True</property>\n        <property name=\"fill\">True</property>\n        <property name=\"position\">1</property>\n      </packing>\n    </child>\n    <child>\n      <object class=\"GtkHButtonBox\" id=\"hbuttonbox1\">\n        <property name=\"visible\">True</property>\n        <property name=\"can_focus\">False</property>\n        <child>\n          <object class=\"GtkButton\" id=\"button_add\">\n            <property name=\"label\">gtk-add</property>\n            <property name=\"use_action_appearance\">False</property>\n            <property name=\"can_focus\">True</property>\n            <property name=\"receives_default\">True</property>\n            <property name=\"use_stock\">True</property>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkButton\" id=\"button_refresh\">\n            <property name=\"label\">gtk-refresh</property>\n            <property name=\"use_action_appearance\">False</property>\n            <property name=\"can_focus\">True</property>\n            <property name=\"receives_default\">True</property>\n            <property name=\"use_stock\">True</property>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">1</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkButton\" id=\"button_remove\">\n            <property name=\"label\">gtk-remove</property>\n            <property name=\"use_action_appearance\">False</property>\n            <property name=\"can_focus\">True</property>\n            <property name=\"receives_default\">True</property>\n            <property name=\"use_stock\">True</property>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n      </object>\n      <packing>\n        <property name=\"expand\">False</property>\n        <property name=\"fill\">True</property>\n        <property name=\"padding\">4</property>\n        <property name=\"position\">2</property>\n      </packing>\n    </child>\n  </object>\n</interface>\n";
