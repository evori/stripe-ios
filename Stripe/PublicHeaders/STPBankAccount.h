//
//  STPBankAccount.h
//  Stripe
//
//  Created by Charles Scalesse on 10/1/14.
//
//

#import <Foundation/Foundation.h>

#import "STPAPIResponseDecodable.h"
#import "STPBankAccountParams.h"

typedef NS_ENUM(NSInteger, STPBankAccountStatus) {
    STPBankAccountStatusNew,
    STPBankAccountStatusValidated,
    STPBankAccountStatusVerified,
    STPBankAccountStatusErrored,
};

/**
 *  Representation of a user's bank account details that have been tokenized with the Stripe API. @see https://stripe.com/docs/api#cards
 */
@interface STPBankAccount : STPBankAccountParams<STPAPIResponseDecodable>

/**
 *  The last 4 digits of the bank account's account number.
 */
- (nonnull NSString *)last4;

/**
 *  The routing number for the bank account. This should be the ACH routing number, not the wire routing number.
 */
@property (nonatomic, copy, nonnull) NSString *routingNumber;

/**
 *  Two-letter ISO code representing the country the bank account is located in.
 */
@property (nonatomic, copy, nullable) NSString *country;

/**
 *  The default currency for the bank account.
 */
@property (nonatomic, copy, nullable) NSString *currency;

/**
 *  The Stripe ID for the bank account.
 */
@property (nonatomic, readonly, nonnull) NSString *bankAccountId;

/**
 *  The last 4 digits of the account number.
 */
@property (nonatomic, readonly, nullable) NSString *last4;

/**
 *  The name of the bank that owns the account.
 */
@property (nonatomic, readonly, nullable) NSString *bankName;

/**
 *  The name of the person or business that owns the bank account.
 */
@property(nonatomic, copy, nullable) NSString *accountHolderName;

/**
 *  The type of entity that holds the account.
 */
@property(nonatomic) STPBankAccountHolderType accountHolderType;

/**
 *  A proxy for the account number, this uniquely identifies the account and can be used to compare equality of different bank accounts.
 */
@property (nonatomic, readonly, nullable) NSString *fingerprint;

/**
 *  The validation status of the bank account. @see STPBankAccountStatus
 */
@property (nonatomic, readonly) STPBankAccountStatus status;

@end
