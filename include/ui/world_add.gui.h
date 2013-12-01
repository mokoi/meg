#define GUIWORLD_ADD "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<interface>\n  <requires lib=\"gtk+\" version=\"2.20\"/>\n  <!-- interface-naming-policy toplevel-contextual -->\n  <object class=\"GtkListStore\" id=\"model1\">\n    <columns>\n      <!-- column-name gchararray -->\n      <column type=\"gchararray\"/>\n    </columns>\n  </object>\n  <object class=\"GtkDialog\" id=\"overview_add\">\n    <property name=\"can_focus\">False</property>\n    <property name=\"title\" translatable=\"yes\">Set Map</property>\n    <property name=\"modal\">True</property>\n    <property name=\"window_position\">center-on-parent</property>\n    <property name=\"destroy_with_parent\">True</property>\n    <property name=\"type_hint\">dialog</property>\n    <child internal-child=\"vbox\">\n      <object class=\"GtkVBox\" id=\"dialog-vbox5\">\n        <property name=\"can_focus\">False</property>\n        <property name=\"spacing\">2</property>\n        <child internal-child=\"action_area\">\n          <object class=\"GtkHButtonBox\" id=\"dialog-action_area5\">\n            <property name=\"can_focus\">False</property>\n            <property name=\"layout_style\">end</property>\n            <child>\n              <object class=\"GtkButton\" id=\"button4\">\n                <property name=\"label\">gtk-apply</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">0</property>\n              </packing>\n            </child>\n            <child>\n              <object class=\"GtkButton\" id=\"buttoncancel\">\n                <property name=\"label\">gtk-cancel</property>\n                <property name=\"use_action_appearance\">False</property>\n                <property name=\"can_focus\">False</property>\n                <property name=\"receives_default\">True</property>\n                <property name=\"use_stock\">True</property>\n              </object>\n              <packing>\n                <property name=\"expand\">False</property>\n                <property name=\"fill\">False</property>\n                <property name=\"position\">1</property>\n              </packing>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">True</property>\n            <property name=\"pack_type\">end</property>\n            <property name=\"position\">0</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkEventBox\" id=\"alchera-title\">\n            <property name=\"can_focus\">False</property>\n            <child>\n              <object class=\"GtkHBox\" id=\"hbox3\">\n                <property name=\"can_focus\">False</property>\n                <child>\n                  <object class=\"GtkImage\" id=\"image7\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"stock\">gtk-about</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">False</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"padding\">2</property>\n                    <property name=\"position\">0</property>\n                  </packing>\n                </child>\n                <child>\n                  <object class=\"GtkLabel\" id=\"alchera-label\">\n                    <property name=\"can_focus\">False</property>\n                    <property name=\"xalign\">0</property>\n                    <property name=\"label\" translatable=\"yes\">&lt;b&gt;Add Map to Current Position&lt;/b&gt;</property>\n                    <property name=\"use_markup\">True</property>\n                  </object>\n                  <packing>\n                    <property name=\"expand\">True</property>\n                    <property name=\"fill\">True</property>\n                    <property name=\"position\">1</property>\n                  </packing>\n                </child>\n              </object>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">1</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkComboBox\" id=\"maps\">\n            <property name=\"can_focus\">False</property>\n            <property name=\"model\">model1</property>\n            <signal name=\"changed\" handler=\"World_MapPreview\" object=\"preview\" swapped=\"yes\"/>\n            <child>\n              <object class=\"GtkCellRendererText\" id=\"renderer1\"/>\n              <attributes>\n                <attribute name=\"text\">0</attribute>\n              </attributes>\n            </child>\n          </object>\n          <packing>\n            <property name=\"expand\">False</property>\n            <property name=\"fill\">False</property>\n            <property name=\"position\">2</property>\n          </packing>\n        </child>\n        <child>\n          <object class=\"GtkImage\" id=\"preview\">\n            <property name=\"can_focus\">False</property>\n            <property name=\"stock\">gtk-about</property>\n          </object>\n          <packing>\n            <property name=\"expand\">True</property>\n            <property name=\"fill\">True</property>\n            <property name=\"position\">3</property>\n          </packing>\n        </child>\n      </object>\n    </child>\n    <action-widgets>\n      <action-widget response=\"-10\">button4</action-widget>\n      <action-widget response=\"0\">buttoncancel</action-widget>\n    </action-widgets>\n  </object>\n</interface>\n";
