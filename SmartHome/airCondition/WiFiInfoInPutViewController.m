
//
//  WiFiInfoInPutViewController.m
//  SmartHome
//
//  Created by 尹啟星 on 16/9/18.
//  Copyright © 2016年 尹啟星. All rights reserved.
//

#import "WiFiInfoInPutViewController.h"

@interface WiFiInfoInPutViewController ()
@property (weak, nonatomic) IBOutlet UILabel *wifiNname;
@property (weak, nonatomic) IBOutlet UITextField *pwdInputTextField;

@end

@implementation WiFiInfoInPutViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.wifiNname.text = [theApp currentSSID];
}
- (IBAction)bind:(UIButton *)sender {
    Log(@"绑定设备-wifi%@--密码：%@",self.wifiNname.text,self.pwdInputTextField.text);
    [DeviceService smartLinkBindWithSSID:[theApp currentSSID] password:self.pwdInputTextField.text timeout:60 success:^(uSDKDevice *dev) {
        
    } faild:^(NSError *error) {
        
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
